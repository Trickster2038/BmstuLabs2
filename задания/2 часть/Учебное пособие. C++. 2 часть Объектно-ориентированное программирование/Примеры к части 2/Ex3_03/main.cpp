#include "Tlongclass.h"
#include <string.h>
#include <iostream>
using namespace std;
class  Treal   // ����� ������������ �����
{  
 public:    Tlong *celn;  // ���� ����� ����� - ��������� �� ������ ������ Tlong
      Tlong *drob;    // ���� ������� ����� - ��������� �� ������ ������ Tlong
      char *real;     // ���� ������������ ����� - ��������� �� ������
      Treal()         // ����������� � �������������� ����������
      {  celn=drob=NULL;  real=NULL;  }
      Treal::Treal(char * st) // ���������������� �����������
      {    setnumv(st);}
      ~Treal()    // ����������
      { 
          if (real!=NULL) delete []real;
          if (celn!=NULL) delete celn;
          if (drob!=NULL) delete drob;  
      }
      void printr();    // ����� ������ ������������� �����
      void setnumv(char * st); // ������������� �����
};
void Treal::setnumv(char * st)
{  
    int l=strlen(st);  char *ptr;   dlong t;    
    real=new char[l+1];   strcpy(real,st);  
    ptr=strchr(real,'.');  
    t=dlong(atol(ptr+1));  *ptr='\0';
    if (t!=0) drob=new Tlong(t);
    t=dlong(atol(real));  *ptr='.';
    if (t!=0) celn=new Tlong(t);
}
void Treal::printr()
{ 
    cout<<"������������ ����� "<<real<<endl;
	if (celn!=NULL) {cout<<"����� �����   :";   celn->print();}   
	if (drob!=NULL) {cout<<"������� ����� :";   drob->print();} 
    cout<<endl; 
}
void main ()
{  
    setlocale(0,"russian");
    Treal a("78457.23065");
    a.printr();
    system("pause");
}
