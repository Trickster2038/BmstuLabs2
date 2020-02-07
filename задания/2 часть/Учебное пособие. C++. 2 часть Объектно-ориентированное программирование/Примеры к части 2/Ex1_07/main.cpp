
#include <locale.h>
#include <string.h>
#include <iostream>
using namespace std;
class sstr
{ 
 private:    char str1[50];
 public:     int x,y;
      sstr(char *vs,int vx,int vy); /* прототип конструктора с  
                                                                              параметрами, заданными  по умолчанию */
      void print(void)
      { 
         cout<<"    Содержимое полей :"<< endl;
         cout<<" x= "<<x<<" y= "<<y<<endl;
         cout<<" str1="<<str1<<endl;
      }
};
sstr::sstr(char * vs="Строка по умолчанию",
           int vx=80,int vy=90) /* тело конструктора с 
                                                          параметрами, заданными по умолчанию */
{ 
     strcpy(str1,vs);
     x=vx;   y=vy;     
}
void main()
{  
    setlocale(0,"russian");
    sstr a0;                   // объект с полями по умолчанию
    sstr a1("Строка");         // объект с заданной строкой   
    sstr a2("Строка",100);     // объект с заданными строкой и x
    sstr a3("Строка",200,150); // объект с заданными строкой, x и y 
    a0.print(); 
    a1.print();  
    a2.print(); 
    a3.print();      
    system("pause");                  
}
