#include <locale.h>
#include <string.h>
#include <iostream>
using namespace std;
class child
{ 
 private:    char name[20];    int  age;
 public:
     void print(void)
     { 
         cout<<" Имя: "<<name;  
         cout<<" Возраст : "<<age<< endl;
     }
     child(char *Name,int Age):age(Age)
     {
         strcpy(name,Name);
     }
 };
void main()
{ 
    setlocale(0,"russian");
    child aa("Мария",6);
    aa.print();    // выводит:   Имя: Мария   Возраст: 6
    child bb=aa;   // вызывает копирующий конструктор
    bb.print();    // выводит:   Имя: Мария   Возраст: 6
    system("pause");  
}

