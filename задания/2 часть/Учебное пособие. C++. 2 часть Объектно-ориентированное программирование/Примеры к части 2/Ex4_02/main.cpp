#include <locale.h>
#include <string.h>
#include <conio.h>
#include <stdio.h>
class String
{    
 public:     char str[40];
     static String *first; //  ����������� ���� - ��������� �� ������ ������
     static String *last; //  ����������� ���� - ��������� �� ����� ������
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
     static void displayAll();    //    ���������� ����������� �������
};
String *String::first=NULL;  //   ������������� ����������� �����������  
String *String::last=NULL;
void String::displayAll()    //    �������� ����������� �������
{ 
     String *p=first;
     if (p==NULL) return;
     do { p->display();  p=p->next; } 
     while (p!=NULL);     
}
void main(void)
{ 
    setlocale(0,"russian");
    String a(" ������ "), b(" ������������� ����������� "),
           c(" �����������");  //   ����������-�������� ���� �������� ������
    if (String::first!=NULL) //  ��������� � ������ ������������ ����
    String::displayAll();  // ��������� � ����������� �������        
    _getch(); 
}
