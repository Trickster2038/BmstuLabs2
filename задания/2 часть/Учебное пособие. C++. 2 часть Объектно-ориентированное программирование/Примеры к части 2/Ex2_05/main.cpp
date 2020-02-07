#include <locale.h>
#include <iostream>
using namespace std;
class fixed
{ 
 protected:  int Fix;
 public:
    fixed() // конструктор без параметров
    {  cout<<" Конструктор класса fixed\n";}
    fixed(int  fix):Fix(fix)  // конструктор c параметром
    {  cout<<" Конструктор класса fixed int\n"; }
};
class derived_1: virtual public fixed //  виртуальное наследование
{ 
 public:      int One;
     derived_1(void) 
     {  cout<<" Конструктор класса derived 1\n"; }
};
class derived_2: virtual private fixed //  виртуальное наследование
{ 
 public:       int Two;
    derived_2(void) 
    {  cout<<" Конструктор класса derived 2\n";}
};
class derived: public derived_1, public derived_2  
        /*  объявление производного класса – непрямого потомка */
{ 
 public:
    derived(void)
    { cout<<" Конструктор класса derived() \n";}
    derived(int fix):fixed(fix) 
    { cout<<" Конструктор класса derived (int) \n";}
    void Out( )  
    { cout<<" Значение поля  Fix = "<< Fix<<endl;}
};
void main()  
{ 
    setlocale(0,"russian");
    derived Var(10);   
    Var.Out( ); 
    system("pause");
}
