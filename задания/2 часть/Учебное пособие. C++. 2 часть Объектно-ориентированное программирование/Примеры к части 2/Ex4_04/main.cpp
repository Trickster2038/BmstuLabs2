#include <locale.h>
#include <iostream>
using namespace std;
class FLOAT; // объ€вление класса без его определени€
class FIXED
{ 
 private:    int a;
 public:     FIXED(int v):a(v){}
     double Add(FLOAT);
     void print(){cout <<a << endl;}
};
class FLOAT
{
 private:    double b;
 public:     FLOAT(double val) { b=val; }
       void print(){   cout <<b << endl;  }
       friend double FIXED::Add(FLOAT); /* компонентна€ функци€ 
                                класса FIXED объ€вл€етс€ дружественной классу FLOAT */
};
double FIXED::Add(FLOAT Par)
{   return a+Par.b;  }   /* функци€ получает доступ к внутреннему 
                                                                                       полю класса FLOAT */
void main()
{ 
    setlocale(0,"russian");
    FIXED aa(25); FLOAT bb(45);
    cout << "–езультаты работы: "<<endl;
    cout<<aa.Add(bb)<<endl;  // выводит:  70
    aa.print();   // выводит: 25
    bb.print();   // выводит: 45
    system("pause"); 
}
