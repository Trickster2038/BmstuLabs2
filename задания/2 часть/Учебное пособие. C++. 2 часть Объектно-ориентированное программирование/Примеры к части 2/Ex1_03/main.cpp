#include <locale.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
class sstro
{   
public:  
	char str1[80];   
	int x,y;
	void set_str(char *vs) // инициализация полей
	{   
		strcpy(str1,vs);   x=0;  y=0; 
	}
	void print(void)       // вывод содержимого полей
	{   
		printf("x=%5d   y=%5d  str: ",x,y); 
		puts(str1);  
	} 
};
void main()
{  
	setlocale(0,"russian");
	sstro aa = {"Строка",200,400}; // инициализированный объект
	sstro bb,cc;   // неинициализированные объекты
	bb.x=200;   // инициализация посредством прямого обращения   
	bb.y=150; 
	strcpy(bb.str1,"Строка");  
	cc.set_str("Строка"); //  вызов инициализирующего метода
	aa.print();  bb.print(); cc.print();
	_getch();
}