#include <locale.h>
#include <iostream>
using namespace std;
class fixed
{ 
 protected:  int Fix;
 public:
    fixed() // ����������� ��� ����������
    {  cout<<" ����������� ������ fixed\n";}
    fixed(int  fix):Fix(fix)  // ����������� c ����������
    {  cout<<" ����������� ������ fixed int\n"; }
};
class derived_1: virtual public fixed //  ����������� ������������
{ 
 public:      int One;
     derived_1(void) 
     {  cout<<" ����������� ������ derived 1\n"; }
};
class derived_2: virtual private fixed //  ����������� ������������
{ 
 public:       int Two;
    derived_2(void) 
    {  cout<<" ����������� ������ derived 2\n";}
};
class derived: public derived_1, public derived_2  
        /*  ���������� ������������ ������ � ��������� ������� */
{ 
 public:
    derived(void)
    { cout<<" ����������� ������ derived() \n";}
    derived(int fix):fixed(fix) 
    { cout<<" ����������� ������ derived (int) \n";}
    void Out( )  
    { cout<<" �������� ����  Fix = "<< Fix<<endl;}
};
void main()  
{ 
    setlocale(0,"russian");
    derived Var(10);   
    Var.Out( ); 
    system("pause");
}
