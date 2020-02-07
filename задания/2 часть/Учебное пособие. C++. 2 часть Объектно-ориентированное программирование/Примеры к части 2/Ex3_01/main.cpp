#include <stdlib.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "Tlongclass.h"
class  Treal   // ����� ������������ �����
{ 
 private:
    Tlong celn; // ��������� ���� - ����� ����� ������������� �����
    Tlong drob; // ��������� ���� - ������� ����� ������������� �����
    char *real; // ������ ������������� �����
 public:
    Treal(){real=NULL;}  // ����������� ��� ���������� 
    Treal(char *st) // ���������������� �����������
    {   setnumv(st);  }
    Treal(dlong c, dlong d): celn(c),drob(d) // �����������
    {                            // �� ������� �������������
        char *s1=new char[10]; 
        ltoa(celn.num,s1,10);
        char *s2=new char[10]; 
        ltoa(drob.num,s2,10);
        int len=strlen(s1)+strlen(s2);
        real=new char [len+1]; 
        strcpy(real,s1);
        strcat(real,s2);
		delete [] s1;
		delete [] s2;
    }
    ~Treal() {  if (real!=NULL) delete [] real;  } // ����������
    void printr();               // ����� ����� �� �����
    void setnumv(char * st);     // ������������� ����� ������
};
void Treal::setnumv(char * st)
{ 
    char *ptr;   
    real=new char[strlen(st)+1];   
    strcpy(real,st);
    ptr=strchr(real,'.');*ptr='\0'; 
    drob.setnum(dlong(atol(ptr+1)));     
    celn.setnum(dlong(atol(real)));    
	*ptr='.';   
}
void Treal::printr()
{ 
    cout<<"������������ ����� :"<<real<<endl;
    cout<<"����� ����� :";    celn.print();    
    cout<<"������� ����� :";  drob.print();     
    cout<<endl;  
}
void main ()
{ 
    setlocale(0,"russian");
    Treal a,b("345678.45567"),d("345678.45567"); 
    a.setnumv("345678.45567");   
	a.printr();   
    b.printr();   
    d.printr();
    _getch(); 
}
