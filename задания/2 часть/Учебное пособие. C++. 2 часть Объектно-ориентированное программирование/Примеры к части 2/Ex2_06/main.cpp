#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;
typedef unsigned long dlong;
class Tlong            // ����� ����� �����
{ 
 public:           
     dlong num;        // �������� ���� ������ 
     Tlong(){}         // ������������������ �����������
     Tlong(dlong an):num(an){} // �����������
     ~Tlong(){}          // ����������
     void print(void)    // ����� �������� ����
     { cout<<"����� ����� : "<<num<<endl; }
     void setnum(dlong an) // ������������� ���� 
     { num=an; }
};
class  Treal: public Tlong    // ����� ������������ �����
{  
 public:
     dlong drob;     // ������� ����� �����
     char *real;     //  ������ ������������� �����
     Treal(){}       // ������������������ �����������
     Treal(char *st) :Tlong() // �����������
           {   setnumv(st); }
     ~Treal()        // ����������
     {   delete real;  }
     void print();  // ����� ������������� ����� (����������������)
     void setnumv(char * st);  // ������������� ����� ������
  };
void Treal::setnumv(char * st)
{ 
    int l;  char *ptr;
    l=strlen(st); real=new char[l+1]; strcpy(real,st);     
    ptr=strchr(real,'.');
    drob=dlong(atol(ptr+1));  *ptr='\0';
    num=dlong(atol(real));    *ptr='.';
}
void Treal::print()
{ 
    cout<<"������������ �����: "<<real<<endl;
	cout<<"����� �����: "; Tlong::print();   
    cout<<"������� �����: "<<drob<<endl;   
}
void main ()
{ 
    setlocale(0,"russian");
    Tlong i(174832); // ������� ������ �������� ������
    i.print();  // ����� ����� ����������������� ������
    Treal a("1748.5932"); // ������� ������ ������������ ������
    a.print();  // ����� ����� ����������������� ������
    system("pause");
}
