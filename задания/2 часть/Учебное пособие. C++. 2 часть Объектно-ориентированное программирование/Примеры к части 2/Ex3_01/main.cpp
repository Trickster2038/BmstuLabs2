#include <stdlib.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "Tlongclass.h"
class  Treal   //  ласс ¬ещественное число
{ 
 private:
    Tlong celn; // объектное поле - цела€ часть вещественного числа
    Tlong drob; // объектное поле - дробна€ часть вещественного числа
    char *real; // запись вещественного числа
 public:
    Treal(){real=NULL;}  // конструктор без параметров 
    Treal(char *st) // инициализирующий конструктор
    {   setnumv(st);  }
    Treal(dlong c, dlong d): celn(c),drob(d) // конструктор
    {                            // со списком инициализации
        char *s1=new char[10]; 
        ltoa(celn.num,s1,10);
        char *s2=new char[10]; 
        ltoa(drob.num,s2,10);
        int len=strlen(s1)+strlen(s2);
        real=new char [len+1]; 
        strcpy(real,s1);
        strcat(real,s2);
		delete [] s1;
		delete [] s2;
    }
    ~Treal() {  if (real!=NULL) delete [] real;  } // деструктор
    void printr();               // вывод числа на экран
    void setnumv(char * st);     // инициализаци€ полей класса
};
void Treal::setnumv(char * st)
{ 
    char *ptr;   
    real=new char[strlen(st)+1];   
    strcpy(real,st);
    ptr=strchr(real,'.');*ptr='\0'; 
    drob.setnum(dlong(atol(ptr+1)));     
    celn.setnum(dlong(atol(real)));    
	*ptr='.';   
}
void Treal::printr()
{ 
    cout<<"¬ещественное число :"<<real<<endl;
    cout<<"÷ела€ часть :";    celn.print();    
    cout<<"ƒробна€ часть :";  drob.print();     
    cout<<endl;  
}
void main ()
{ 
    setlocale(0,"russian");
    Treal a,b("345678.45567"),d("345678.45567"); 
    a.setnumv("345678.45567");   
	a.printr();   
    b.printr();   
    d.printr();
    _getch(); 
}
