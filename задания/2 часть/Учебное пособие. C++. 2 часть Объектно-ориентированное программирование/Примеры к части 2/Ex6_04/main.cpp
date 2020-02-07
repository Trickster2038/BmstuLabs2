#include <locale.h>
#include <string.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
template <class type> // ���������� ������� ������ 
class arrayob         // ����� ������������ ������
{ 
   type **contents;   // ������ ���������� �� ������� ���� type
   int size;          // ������������ ���������� �������� � �������
   int n;             // �������� ���������� �������� � �������
 public:
   arrayob(int number)  
   { contents=new type * [size=number];} 
   ~arrayob ();
   void add(type *p)
   {  
      if(n==size)cerr<<"����� �� �������";   
      else {contents[n]=p; n++;} 
   }
   type & operator [] (int x)    //  �������� ������� ��������  
   { 
      if ((x<0)||(x>=size)) 
      { cerr <<"��������� ������ "<<x<<endl;x=0;}
      return *contents[x]; 
   }
   int sizeofmas(){return n;}  // �������� ������ �������
};
template <class type> arrayob<type>::~arrayob ()  
{ 
   for(int i=0;i<size;i++) delete contents[i]; 
   delete []contents;
}
class TNum               // �����  �����
{
 public: 	int num;
    virtual void Print(void) { cout<<num<<" "; }
    TNum(){cout<<"������� �����"<<endl; cin>>num;}
    TNum(int n):num(n) {}
    virtual ~TNum(void){}
};
class TStr:public TNum   // ����� ������
{ 
 public:	 char *st;
    virtual void Print(void) { TNum::Print(); cout<<st<<" ";}
    TStr();    // ����������� �� ���������
    TStr(char *s):TNum(strlen(s))// ����������� � �����������
    {
        st=new char[num+1];    strcpy(st,s);  
        st[num]='\0';   
    }
    virtual ~TStr(void){ delete [] st;}
};
TStr::TStr():TNum(40)
{   
    cout<<"������� ������ "<<endl;
    st=new char[num+1];   cin>>st;
    num=strlen(st);  st[num+1]='\0';    
}
arrayob<TNum>  ob_a(5); //������ �� 5 ���������� �� �������                                                                                         
void main()
{
    setlocale(0,"russian");
    int i;
    for(i=0;i<5;i++)    
       if (i/2*2==i) 
         ob_a.add(new TNum);   // �������� �����
    else ob_a.add(new TStr);   // �������� ������                 
    cout<<"���������� ���������� "<<"\n";
    for (i=0;i<ob_a.sizeofmas();i++) 
       ob_a[i].Print();
    system("pause");
}
