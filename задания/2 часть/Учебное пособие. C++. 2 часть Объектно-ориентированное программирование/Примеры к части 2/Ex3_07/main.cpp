#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <locale.h>
class TElement      // ����������� ����� ������� ������
{ 
 public: TElement *pre,*suc;
    TElement(void) { pre=suc=NULL;}  // �����������
    virtual void Print(void)=0;  // ����������� ����� ������
};

class TNum: public TElement  //  ����� �����
{
 public:  int num;       // �������� ���� ������ ����
    virtual void Print(void) { printf("%d ",num); }
    TNum(){}        // ����������� �� ���������
    TNum(int n):num(n) {}      // �����������
};

class TStr: public TNum   // ����� ������ (num - ����� ������)
{ 
 public:   char st[40];    // ���� ���������� ������
    TStr(){}        // ����������� �� ���������
    TStr(char *s):TNum(strlen(s))
    {
        strcpy(st,s); 
        if (num>=40)st[40]='\0'; else st[num+1]='\0';
    }
    virtual void Print(void) 
    {   TNum::Print(); printf("%s\n",st);  }
};
class TTabl: public TStr // ����� ������� - ��������� ������
{
 public:    char str[20];
    virtual void Print(void) 
    {  TStr::Print();  printf("%s\n  ",str); }
    TTabl(){}   // ����������� �� ���������
    TTabl(char *s,char *s2):TStr(s)
    {
        strcpy(str,s2);
        if (strlen(s2)>=20) str[20]='\0';  
        else str[strlen(s2)+1]='\0'; 
     }
};


class TSpisok        // ����� ������
{
 protected: TElement *first,*last,*cur;  
 public:
     TSpisok(void){ first=last=cur=NULL;} // �����������
     ~TSpisok();   // ����������
     void Add(TElement *e); // ���������� �������� � ������
	TElement *Del(void);  // �������� �������� �� ������
     // �������-���������
	TElement * ifirst()  // ��������� �� ������ �������
	{    return cur=first; }
	TElement * inext()   // ��������� �� ��������� �������
	{    return cur=cur->suc; }
};
TSpisok::~TSpisok()
{
     while ((cur=Del())!=NULL)  
     { cur->Print();   delete(cur); }    
}
void TSpisok::Add(TElement *e)
{
    if (first==NULL)  first=last=e;
    else {   e->suc=first; first=first->pre=e;}  
}
TElement *TSpisok::Del(void)
{ 
    TElement *temp=last;
    if (last!=NULL) 
    { 
        last=last->pre;  
        if (last!=NULL) last->suc=NULL; 
    }
    if (last==NULL) first=NULL;    
    return temp;   
}

TSpisok N;     // ���������� ������� ������ ������
void main(void)
{
	setlocale(0,"russian");
    int k;  char str[40];  char str2[20];
    TElement *p;
    // ���� ������������ ������ �� ��������� ������� TNum, TStr, TTabl
    while(printf("������� �����:"), scanf("%d",&k)!=EOF)
    { 
        p=new TNum(k);     N.Add(p);
        printf("������� ������:");    scanf("%s",str);
        printf("������� ������ 2:");  scanf("%s",str2);
        p=new TTabl(str,str2);     N.Add(p);
        printf("������� ������:");    scanf("%s",str);
        p=new TStr(str);           N.Add(p); 
    }
    puts("\n������� ��������:");
        // ���� ��������� ������� �������� ������ � ������� ����������
    p=N.ifirst();
    while (p!=NULL) 
    {    p->Print();   p=N.inext();  } 
    _getch();
}
