#include <locale.h>
#include <string.h>
#include <iostream>
using namespace std;
class sstr
{ 
 private:   char str[40];
 public:    int x,y;
    void print(void)
    { 
        cout<<"Cодержимое полей : "<< endl;
        cout<<"x= "<<x<<" y= "<<y<<"  str= "<<str<<endl;
    }
    sstr(){} // неинициализирующий конструктор
    sstr(int vx,int vy,char *vs="Cтрока по умолчанию")
    {  setstr(vx,vy,vs); }
    ~sstr() {} // деструктор
    void setstr(int ax,int ay,char *vs); /* инициализация
                                                                                                             полей объекта */
};
void  sstr::setstr(int ax,int ay,char *vs)
{ 
    if (strlen(vs)>=40) 
    {  strncpy(str,vs,40);   str[40]='\0'; } 
    else strcpy(str,vs);
    x=ax;  y=ay;   
}
void main()
{
    setlocale(0,"russian");
    sstr  *a[5],  // массив указателей на пять динамических объектов
           *c;    // указатель на массив динамических объектов
    int i,j;
    char *vs="Строка";   //выделить память и инициализировать объект 
    for(int i=0;i<5;i++) // создать массив динамических объектов         
       a[i]=new sstr(10+i,10+2*i,"aaaa"+i); 
    cout<<"  Массив объектов a"<<endl;
    for(i=0;i<5;i++) // вывести содержимое полей объектов
    { 
        cout<<"Элемент "<< i+1; 
        a[i]->print();
    } 
    for(i=0;i<5;i++) delete a[i];      // освободить память 
    c=new sstr[3];     // выделить память под три динамических объекта
    for(i=0;i<3;i++)   //  инициализировать поля динамических объектов
      (c+i)->setstr(15+i,12+i*2,vs+i); 
    cout<<"  Массив объектов c"<<endl;
    for(i=0;i<3;i++)  // вывести содержимое полей объектов
    { 
       cout<<"Элемент "<< i+1;  
       (c+i)->print();
    } 
    delete []c; // освободить память
    system("pause");  
}
