#include <locale.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
class Tpole  // абстрактный класс  Поле
{ 
 public:   
    Tpole() {}
    virtual void Print(void)=0; // абстрактная функция
};
class Tnumpole:public Tpole     // класс Число
{ 
 private: int num;
 public:
    Tnumpole(int n):num(n){}
    void Print(void)   /* аспект виртуальной функции*/
    {   printf("Число =  %5d\n",num);  }
};
class Tstrpole:public Tpole    // класс Строка
{ 
 private: char str[10];
 public :
    Tstrpole(char *st) {  strcpy(str,st);  }
    void Print(void)   /* аспект виртуальной  функции*/
    {   printf("Строка = %s\n",str);  }
};
void main()
{ 
    setlocale(0,"russian");
    int n,i; char st[80];
    Tpole *a[10];  // массив указателей на объекты класса Tpole
    for(i=0;i<10;i++)
    { 
       printf("\nВведите целое число или строку: ");
       scanf_s("%s",st,80);
       if ((n=atoi(st))!=0||
                (strlen(st)==1 && st[0]=='0'))
           a[i]=new Tnumpole(n); // Число
       else
           a[i]=new Tstrpole(st); // Строка
    }
    for(i=0;i<10;i++)  a[i]->Print(); 
    for(i=0;i<10;i++) delete a[i]; 
    _getch();
}
