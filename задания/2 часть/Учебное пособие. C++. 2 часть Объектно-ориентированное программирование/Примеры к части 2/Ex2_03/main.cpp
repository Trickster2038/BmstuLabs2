#include <iostream>
using namespace std;
class A
{ 
 private:       int x;
 protected:     int y;
 public:        int z;
     void print(void)
     { 
          cout<<"x = "<<x<<endl;
          cout<<"y = "<<y<<endl;
          cout<<"z = "<<z<<endl;
     }
     A(){x=20; y=30; z=50;}
 };
class B: private A   // все компоненты класса A не доступны в классе B
{ 
  protected: A::y; /* защищенное поле класса A, 
                                   объ€вл€етс€ доступным в классе B */
  public:    A::z; /* общее поле класса A, 
                                   объ€вл€етс€ доступным в классе B */
     B():A(){}
     void print(void)
     { 
        cout<<"y = "<<y<<endl;
        cout<<"z = "<<z<<endl;
     }
   };
void main()
{  
    A aa; // создание объекта базового класса
    B bb; // создание объекта производного класса
    aa.print();   // выводит:  x = 20  y = 30  z = 50
    bb.print();   // выводит:  y = 30  z = 50
    system("pause");
}
