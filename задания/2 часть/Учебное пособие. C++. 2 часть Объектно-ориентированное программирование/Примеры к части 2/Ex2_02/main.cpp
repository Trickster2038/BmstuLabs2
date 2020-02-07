#include <locale.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;
typedef  unsigned  long  dlong;
class Tlong                 // Класс Целое число
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
};
class  Treal: public Tlong    // Класс Вещественное число
{  
 public:
     dlong drob;     // дробная часть числа
     char *real;     //  запись вещественного числа
     Treal(){real=NULL;}       // конструктор без параметров
     Treal(char *st) :Tlong() // инициализирующий конструктор
           {   setnumv(st); }
     ~Treal()        // деструктор
     {  if (real!=NULL) delete [] real;  }
     void printr();  // вывод вещественного числа
     void setnumv(char * st);  // инициализация полей класса
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
    cout<<"Вещественное число: "<<real<<endl;
    cout<<"Целая часть: "; print();   
    cout<<"Дробная часть: "<<drob<<endl;   
}
void main ()
{ 
    setlocale(0,"russian");
    Treal a("456789.1234321"), // объект производного класса
          *pa=new Treal("456789.1234321"), // указатель
          mask[3]= // инициализированный массив объектов
                           {Treal("1748.5932"),
            Treal("4567.34321"),
            Treal("18689.9421")};
    a.printr();
    pa->printr();     delete pa;   
    for(int i=0;i<3;i++)
    { 
        cout<<"Элемент массива "<<(i+1)<<": "<<endl;
        mask[i].printr();
    }
    system("pause");
}
