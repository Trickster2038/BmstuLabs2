#include <locale.h>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include  <time.h>
using namespace std;
class first
{  
 public:    int num_f;
    first(int va):num_f(va)  
    {  cout<<"Конструктор first\n";  }
};
class second
{ 
 public:     char c_s;   int num_s; 
    second(int vn):num_s(vn)   
    {  cout<<"Конструктор second\n"; }
};
class third:private first, // сокрытие базового класса
            public second  // открытый базовый класс
{  
 public:
     third(int nm,char vc,int nfx):
        first(nfx), second(nm)  
     { 
         cout<<"Конструктор third\n";    
         c_s=vc; /* инициализация поля базового класса 
                                          конструктором производного класса */
     }
     int get(void)    // получение значения внутреннего поля
     {  return num_f;  }  
};
void main()
{  
    setlocale(0,"russian");
    srand((unsigned)time(NULL)); // инициализация датчика случайных чисел 
    int r=rand()/1000-rand()/1000; // присвоение числу случайного значения
    third aa(r,'R',50);
    cout<<aa.get()<<" "<<aa.c_s<<" "<<aa.num_s<<endl;
    _getch(); 
}
