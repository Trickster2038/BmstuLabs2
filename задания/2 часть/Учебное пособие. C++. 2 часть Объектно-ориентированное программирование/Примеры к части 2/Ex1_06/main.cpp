#include <locale.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
class sstr
{
 private:     char str1[60];
 public:      int x,y;
     sstr() // стандартная инициализация всех полей
	{ 
         strcpy(str1,"Строка по умолчанию.");
         x=0;  y=0;  
     } 
     sstr(char *vs) // инициализация поля str1
     { 
         strcpy(str1,vs);
         x=0;   y=0;  
     }  
     sstr(char *vs,int vx) // инициализация поля str1 и x
     { 
          strcpy(str1,vs);
          x=vx;   y=0; 
     }   
     sstr(char *vs,int vx,int vy)// инициализация всех полей
     { 
          strcpy(str1,vs);
          x=vx;  y=vy;      
     }
     void print(void)
     { 
         puts("Значения полей объекта: ");
         printf("x=  %5d  y= %5d \n",x,y);
         printf("str1= ");    puts(str1);
     }
};
void main()
{  
    setlocale(0,"russian");
    sstr a0;                   // объект с полями по умолчанию
    sstr a1("Строка");         // объект с заданной строкой   
    sstr a2("Строка",100);     // объект с заданными строкой и x
    sstr a3("Строка",200,150); // полностью инициализированный объект 
    a0.print(); a1.print(); a2.print(); a3.print();      
    _getch(); 
}
