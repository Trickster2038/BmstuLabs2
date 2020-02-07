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
    num=dlong(atol(real));    *ptr='.';
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
    Tlong i(174832); // простой объект базового класса
    i.show();  // косвенный вызов переопределяемого метода класса
    Treal a("1748.5932"); // простой объект производного класса
    a.show();     // выводит только целую часть числа (ошибка!)
    Treal *pa=new Treal("456789.1234321"); /* указатель на объект 
                                                                                     производного класса */
    pa->print(); // явный вызов переопределенного метода
    pa->show(); // выводит только целую часть числа (ошибка!)
    delete pa;   // вызывает деструктор производного класса
    Tlong *pb=new Treal("234567.34765");/* указатель 
                                        базового класса, объект производного класса */
    pb->print();    // выводит только целую часть числа (ошибка!)
    delete pb;        // неявно вызывается деструктор класса Tlong (ошибка!)
    show_ext(a);    // выводит только целую часть числа (ошибка!)
    system("pause");
}
