#include <locale.h>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include  <time.h>
using namespace std;
class first
{  
 public:    int num_f;
    first(int va):num_f(va)  
    {  cout<<"����������� first\n";  }
};
class second
{ 
 public:     char c_s;   int num_s; 
    second(int vn):num_s(vn)   
    {  cout<<"����������� second\n"; }
};
class third:private first, // �������� �������� ������
            public second  // �������� ������� �����
{  
 public:
     third(int nm,char vc,int nfx):
        first(nfx), second(nm)  
     { 
         cout<<"����������� third\n";    
         c_s=vc; /* ������������� ���� �������� ������ 
                                          ������������� ������������ ������ */
     }
     int get(void)    // ��������� �������� ����������� ����
     {  return num_f;  }  
};
void main()
{  
    setlocale(0,"russian");
    srand((unsigned)time(NULL)); // ������������� ������� ��������� ����� 
    int r=rand()/1000-rand()/1000; // ���������� ����� ���������� ��������
    third aa(r,'R',50);
    cout<<aa.get()<<" "<<aa.c_s<<" "<<aa.num_s<<endl;
    _getch(); 
}
