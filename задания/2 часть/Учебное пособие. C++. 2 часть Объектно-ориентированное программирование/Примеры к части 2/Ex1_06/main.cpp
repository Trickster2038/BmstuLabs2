#include <locale.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
class sstr
{
 private:     char str1[60];
 public:      int x,y;
     sstr() // ����������� ������������� ���� �����
	{ 
         strcpy(str1,"������ �� ���������.");
         x=0;  y=0;  
     } 
     sstr(char *vs) // ������������� ���� str1
     { 
         strcpy(str1,vs);
         x=0;   y=0;  
     }  
     sstr(char *vs,int vx) // ������������� ���� str1 � x
     { 
          strcpy(str1,vs);
          x=vx;   y=0; 
     }   
     sstr(char *vs,int vx,int vy)// ������������� ���� �����
     { 
          strcpy(str1,vs);
          x=vx;  y=vy;      
     }
     void print(void)
     { 
         puts("�������� ����� �������: ");
         printf("x=  %5d  y= %5d \n",x,y);
         printf("str1= ");    puts(str1);
     }
};
void main()
{  
    setlocale(0,"russian");
    sstr a0;                   // ������ � ������ �� ���������
    sstr a1("������");         // ������ � �������� �������   
    sstr a2("������",100);     // ������ � ��������� ������� � x
    sstr a3("������",200,150); // ��������� ������������������ ������ 
    a0.print(); a1.print(); a2.print(); a3.print();      
    _getch(); 
}
