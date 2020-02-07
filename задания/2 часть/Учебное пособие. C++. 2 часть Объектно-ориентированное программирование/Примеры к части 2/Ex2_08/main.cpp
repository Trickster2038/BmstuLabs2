
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
     virtual ~Tlong(){}          // деструктор
     virtual void print(void)    // вывод значения поля
           { cout<<" Целое число : "<<num<<endl; }
     void setnum(dlong an) // инициализации поля 
     { num=an; }
     void show()  // метод, вызывающий переопределяемый метод 
     { print(); }
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
    num=dlong(atol(real));
    *ptr='.';
}
void Treal::print()
{ 
    cout<<"Вещественное число: "<<real<<endl;
    cout<<"Целая часть: "; Tlong::print();   
    cout<<"Дробная часть: "<<drob<<endl;   
}
// Внешняя функция с параметром - ссылкой на базовый класс Tlong
void show_ext(Tlong &par)     
{  par.print(); }

void main ()
{ 
    setlocale(0,"russian");
    Treal a("1748.5932"); // простой объект производного класса
    a.show();     // вызывает метод Print() производного класса
    Treal *pa=new Treal("456789.1234321"); /* указатель и объект 
                                                                                     производного класса */
    pa->show(); // вызывает метод Print() производного класса
    delete pa;   // вызывает деструктор производного класса
    Tlong *pb=new Treal("234567.34765");/* указатель 
                                        базового класса, объект производного класса */

    pb->print();    // вызывает метод Print() производного класса
    delete pb;        // вызывает деструктор производного класса
    show_ext(a);    // вызывает метод Print() производного класса
    system("pause");
}
