#include <locale.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;
typedef  unsigned  long  dlong;
class Tlong                 // ����� ����� �����
{ 
 public:           
     dlong num;        // �������� ���� ������ 
     Tlong(){}         // ������������������ �����������
     Tlong(dlong an):num(an){} // �����������
     ~Tlong(){}          // ����������
     void print(void)    // ����� �������� ����
           { cout<<" ����� ����� : "<<num<<endl; }
     void setnum(dlong an) // ������������� ���� 
     { num=an; }
};
class  Treal: public Tlong    // ����� ������������ �����
{  
 public:
     dlong drob;     // ������� ����� �����
     char *real;     //  ������ ������������� �����
     Treal(){real=NULL;}       // ����������� ��� ����������
     Treal(char *st) :Tlong() // ���������������� �����������
           {   setnumv(st); }
     ~Treal()        // ����������
     {  if (real!=NULL) delete [] real;  }
     void printr();  // ����� ������������� �����
     void setnumv(char * st);  // ������������� ����� ������
  };
void Treal::setnumv(char * st)
{ 
    int l=strlen(st);  char *ptr;
    real=new char[l+1]; strcpy(real,st);     
    ptr=strchr(real,'.');
    drob=dlong(atol(ptr+1));  *ptr='\0';
    num=dlong(atol(real));    *ptr='.';
}
void Treal::printr()
{ 
    cout<<"������������ �����: "<<real<<endl;
    cout<<"����� �����: "; print();   
    cout<<"������� �����: "<<drob<<endl;   
}
void main ()
{ 
    setlocale(0,"russian");
    Treal a("456789.1234321"), // ������ ������������ ������
          *pa=new Treal("456789.1234321"), // ���������
          mask[3]= // ������������������ ������ ��������
                           {Treal("1748.5932"),
            Treal("4567.34321"),
            Treal("18689.9421")};
    a.printr();
    pa->printr();     delete pa;   
    for(int i=0;i<3;i++)
    { 
        cout<<"������� ������� "<<(i+1)<<": "<<endl;
        mask[i].printr();
    }
    system("pause");
}
