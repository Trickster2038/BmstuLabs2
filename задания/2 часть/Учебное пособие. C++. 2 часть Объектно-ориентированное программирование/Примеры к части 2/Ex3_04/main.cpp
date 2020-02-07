#include <locale.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
class integ
{
 protected: int n;
 public:
    integ(int vn) { n=vn; } // конструктор
    virtual ~integ() {}     // деструктор
    virtual void print(void) { cout<<"  "<<n<<endl;}
};
class masinteg: public integ
{
    int *mas;
 public:      masinteg(int vn);       // конструктор
    ~masinteg(){ delete [] mas; } // деструктор
     void print(void);
 };
masinteg::masinteg(int vn):integ(vn)
{ 
      mas=new int[n];     
      for(int i=0;i<n;i++)  mas[i]=rand()/1000;
}
void masinteg::print()
{
    for(int i=0;i<n;i++) 
    {  cout<<"  " <<mas[i];   cout<< endl; }  
}
void main()
{
    setlocale(0,"russian"); 
    srand( (unsigned)time( NULL ) );
    integ *pa;       // указатель на базовый класс 
    pa=new integ(5); // создание объекта базового класса
    pa->print();
    delete pa;     // автоматический вызов деструктора integ
    pa=new masinteg(6); // создание объекта производного  класса
    pa->print();
    delete pa;    // автоматический вызов деструктора masinteg
    system("pause");
}
