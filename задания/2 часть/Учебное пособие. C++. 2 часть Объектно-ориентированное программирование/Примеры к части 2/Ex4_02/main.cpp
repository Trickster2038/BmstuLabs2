#include <locale.h>
#include <string.h>
#include <conio.h>
#include <stdio.h>
class String
{    
 public:     char str[40];
     static String *first; //  статическое поле - указатель на начало списка
     static String *last; //  статическое поле - указатель на конец списка
     String *next;
     String(char  *s)
     {  
         strcpy(str,s);       
         next=NULL;
         if (first==NULL) first=this; 
         else last->next=this;           
         last=this;    
     }
     void display()   {  puts(str);  }
     static void displayAll();    //    объявление статической функции
};
String *String::first=NULL;  //   инициализация статических компонентов  
String *String::last=NULL;
void String::displayAll()    //    описание статической функции
{ 
     String *p=first;
     if (p==NULL) return;
     do { p->display();  p=p->next; } 
     while (p!=NULL);     
}
void main(void)
{ 
    setlocale(0,"russian");
    String a(" Пример "), b(" использования статических "),
           c(" компонентов");  //   объявление-создание трех объектов класса
    if (String::first!=NULL) //  обращение к общему статическому полю
    String::displayAll();  // обращение к статической функции        
    _getch(); 
}
