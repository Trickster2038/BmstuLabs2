#include <locale.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
class TElement      // ����������� ����� ������� ������
{ 
 public: TElement *pre,*suc;
    TElement(void) { pre=suc=NULL;}  // �����������
    virtual void Print(void)=0;  // ����������� ����� ������
};
class TSpisok        // ����� C�����
{
 protected: TElement *first,*last,*cur; /*��������� �� ������,
                                                     ��������� � ������� �������� ������ */
 public:  TSpisok(void){ first=last=cur=NULL;}
     ~TSpisok();   // ����������
     void Add(TElement *e); // ���������� �������� � ������
     TElement *Del(void);   // �������� �������� �� ������
     void ForEach(void (*f)(TElement *e)); // ������������ ��������� 
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
void TSpisok::ForEach(void (*f)(TElement *e))
{ 
    cur=first;  
    while (cur!=NULL) { (*f)(cur); cur=cur->suc;}  
}
class TSortSpisok:public TSpisok // ����� C������������ ������
{    
  protected:
     virtual int Compare(void *op1,void *op2)=0; /* ����������� �����
                                                       ��������� ��� ��������� ����������  */
  public:
     void Sort(void);        // ����� ����������
     TSortSpisok(void):TSpisok(){}      // �����������
     ~TSortSpisok(){}       // ����������
};
void TSortSpisok::Sort(void)
{
    int swap=1;      TElement *temp;
    while (swap)  
    {
        swap=0;  cur=first; 
        while (cur->suc!=NULL)
        {
            if (Compare(cur,cur->suc))
            { 
                temp=cur->suc; 
                cur->suc=temp->suc; 
                temp->suc=cur;
                if (cur->pre!=NULL)  
                     cur->pre->suc=temp;  
                else first=temp;
                temp->pre=cur->pre;   
                cur->pre=temp;
                if (cur->suc!=NULL)  
                     cur->suc->pre=cur;   
                else last=cur;
                cur=temp; swap=1;
            }
            else cur=cur->suc;  
        }            
    }
}
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
class TSSpisok:public TSortSpisok /*  ����� ����������������                                                                                
                                                                       ������������� ������*/
{
 protected:
    virtual int Compare(void *op1,void *op2) /* ����� 
                 ��������� ��� ��������� ���������� � ����� ��������������� ���� */
    { return  (((TTabl *)op1)->num)<(((TTabl *)op2)->num);}
 public:
    TSSpisok(void):TSortSpisok(){}
    ~TSSpisok(void){}
};
void Show(TElement *e)  // ��������� ��� �������� � ����� ForEach 
{   e->Print(); }
TSSpisok N;         // ������ ������ ������������� ������
void main()
{ 
    setlocale(0,"russian");
    int k;    char str[40];    char str2[20];
    TElement *p; //  ��������� �� ������� ����� Telement
    // ���� ������������ ������ �� �������� ������� TNum, TStr, TTabl
    while ( printf("������� �����:"),scanf("%d",&k)!=EOF)
    { 
        p=new TNum(k);   N.Add(p);
        printf("������� ������:");  scanf("%s",str);
        printf("������� ������ 2:"); scanf("%s",str2);
        p=new TTabl(str,str2);      N.Add(p);
        printf("������� ������:");  scanf("%s",str);
        p=new TStr(str);            N.Add(p);     
    }
    puts("\n������� ��������:");
    N.ForEach(Show);   // ����� ��������� ������
    N.Sort();          // ����������
     puts("\n����� ����������:");
     N.ForEach(Show);       
	_getch();
}
