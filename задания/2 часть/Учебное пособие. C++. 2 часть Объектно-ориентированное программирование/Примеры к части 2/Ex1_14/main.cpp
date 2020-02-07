#include <locale.h>
#include <iostream>
#include <iomanip>
using namespace std;
class TVector
{ 
 private:    int x,y,z;
 public:
    TVector(){} // неинициализирующий конструктор
    TVector(int ax,int ay,int az) // инициализирующий конструктор
    {  x=ax;y=ay;z=az; }
    ~TVector(){} // деструктор
    void PrintVec();
    void SetVec(int ax,int ay,int az) // инициализирующий метод
    {  x=ax;y=ay;z=az; }
};
void TVector::PrintVec()
{ 
    cout<<"Значение вектора: "<<setw(5)<<x<<" , ";
    cout<<setw(5)<<y<<" , "<<setw(5)<<z<<"\n";    
}
void main()
{
    setlocale(0,"russian");
    TVector *a,*b; //  два указателя на объекты класса
         // выделяем память под динамические объекты класса 
    a=new TVector(12,34,23); // инициализированный объект
    b=new TVector;      // неинициализированный объект
    b->SetVec(10,45,56); // инициализация объекта
    a->PrintVec();    //  выводит: 12,  34,  23
    b->PrintVec();    //  выводит: 10,  45,  56
    // освобождаем память, выделенную под динамические объекты класса 
    delete a;         // вызывает деструктор
    delete b;         // вызывает деструктор
    system("pause");  
}
