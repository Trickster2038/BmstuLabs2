#include <iostream>

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
