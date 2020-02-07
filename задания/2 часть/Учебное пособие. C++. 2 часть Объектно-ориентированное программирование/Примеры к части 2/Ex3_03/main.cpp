#include "Tlongclass.h"
#include <string.h>
#include <iostream>
using namespace std;
class  Treal   //  ласс ¬ещественное число
{  
 public:    Tlong *celn;  // поле цела€ часть - указатель на объект класса Tlong
      Tlong *drob;    // поле дробна€ часть - указатель на объект класса Tlong
      char *real;     // поле вещественное число - указатель на строку
      Treal()         // конструктор с инициализацией указателей
      {  celn=drob=NULL;  real=NULL;  }
      Treal::Treal(char * st) // инициализирующий конструктор
      {    setnumv(st);}
      ~Treal()    // деструктор
      { 
          if (real!=NULL) delete []real;
          if (celn!=NULL) delete celn;
          if (drob!=NULL) delete drob;  
      }
      void printr();    // вывод записи вещественного числа
      void setnumv(char * st); // инициализаци€ полей
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
    cout<<"¬ещественное число "<<real<<endl;
	if (celn!=NULL) {cout<<"÷ела€ часть   :";   celn->print();}   
	if (drob!=NULL) {cout<<"ƒробна€ часть :";   drob->print();} 
    cout<<endl; 
}
void main ()
{  
    setlocale(0,"russian");
    Treal a("78457.23065");
    a.printr();
    system("pause");
}
