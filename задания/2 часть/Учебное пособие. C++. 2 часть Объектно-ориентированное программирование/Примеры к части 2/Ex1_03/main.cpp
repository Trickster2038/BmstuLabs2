#include <locale.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
class sstro
{   
public:  
	char str1[80];   
	int x,y;
	void set_str(char *vs) // ������������� �����
	{   
		strcpy(str1,vs);   x=0;  y=0; 
	}
	void print(void)       // ����� ����������� �����
	{   
		printf("x=%5d   y=%5d  str: ",x,y); 
		puts(str1);  
	} 
};
void main()
{  
	setlocale(0,"russian");
	sstro aa = {"������",200,400}; // ������������������ ������
	sstro bb,cc;   // �������������������� �������
	bb.x=200;   // ������������� ����������� ������� ���������   
	bb.y=150; 
	strcpy(bb.str1,"������");  
	cc.set_str("������"); //  ����� ����������������� ������
	aa.print();  bb.print(); cc.print();
	_getch();
}