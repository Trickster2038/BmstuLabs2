#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;
typedef unsigned long dlong;
class Tlong            // Класс Целое число
{ 
 public:           
     dlong num;        // числовое поле класса 
     Tlong(){}         // неинициализирующий конструктор
     Tlong(dlong an):num(an){} // конструктор
     ~Tlong(){}          // деструктор
     void print(void)    // вывод значения поля
     { cout<<"Целое число : "<<num<<endl; }
     void setnum(dlong an) // инициализации поля 
     { num=an; }
};
class  Treal: public Tlong    // Класс Вещественное число
{  
 public:
     dlong drob;     // дробная часть числа
     char *real;     //  запись вещественного числа
     Treal(){}       // неинициализирующий конструктор
     Treal(char *st) :Tlong() // конструктор
           {   setnumv(st); }
     ~Treal()        // деструктор
     {   delete real;  }
     void print();  // вывод вещественного числа (переопределяется)
     void setnumv(char * st);  // инициализация полей класса
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
    cout<<"Вещественное число: "<<real<<endl;
	cout<<"Целая часть: "; Tlong::print();   
    cout<<"Дробная часть: "<<drob<<endl;   
}
void main ()
{ 
    setlocale(0,"russian");
    Tlong i(174832); // простой объект базового класса
    i.print();  // явный вызов переопределяемого метода
    Treal a("1748.5932"); // простой объект производного класса
    a.print();  // явный вызов переопределенного метода
    system("pause");
}
