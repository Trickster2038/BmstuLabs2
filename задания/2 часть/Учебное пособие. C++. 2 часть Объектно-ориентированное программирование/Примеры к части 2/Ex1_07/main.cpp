
#include <locale.h>
#include <string.h>
#include <iostream>
using namespace std;
class sstr
{ 
 private:    char str1[50];
 public:     int x,y;
      sstr(char *vs,int vx,int vy); /* �������� ������������ �  
                                                                              �����������, ���������  �� ��������� */
      void print(void)
      { 
         cout<<"    ���������� ����� :"<< endl;
         cout<<" x= "<<x<<" y= "<<y<<endl;
         cout<<" str1="<<str1<<endl;
      }
};
sstr::sstr(char * vs="������ �� ���������",
           int vx=80,int vy=90) /* ���� ������������ � 
                                                          �����������, ��������� �� ��������� */
{ 
     strcpy(str1,vs);
     x=vx;   y=vy;     
}
void main()
{  
    setlocale(0,"russian");
    sstr a0;                   // ������ � ������ �� ���������
    sstr a1("������");         // ������ � �������� �������   
    sstr a2("������",100);     // ������ � ��������� ������� � x
    sstr a3("������",200,150); // ������ � ��������� �������, x � y 
    a0.print(); 
    a1.print();  
    a2.print(); 
    a3.print();      
    system("pause");                  
}
