#include <locale.h>
#include <iostream>
using namespace std;
class Num
{    
    int n;
 public:
    Num(int an):n(an){} // инициализирующий конструктор
    Num(const Num& ob) // копирующий конструктор
    {  n = ob.n*3; }
    void print(void)    
    { cout<<" Поле n ="<<n<<"  "<< endl; }
};
void main()
{  
    setlocale(0,"russian");
    Num aa(10);      // вызывается инициализирующий конструктор
    aa.print();      // выводит Поле n = 10
    Num bb=aa;       // вызывается копирующий конструктор
    bb.print();      // выводит Поле n = 30
    system("pause");  
}
