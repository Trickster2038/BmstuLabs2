#include "Tlongclass.h"
#include <conio.h>
class     mastlong   // ����� ������ ����� �����
{
 private:    dlong  size;   // ������ �������
    Tlong  mas[10];  // ������ �������� ������ Tlong
 public: 
    mastlong(){}    // ������������������ �����������
    mastlong(dlong af,dlong m1[]) // ����������� � �����������
    {  setmas(af,m1);  }
    ~mastlong(){}   // ����������
    void  printm();  // ����� ��������� ������� �� �����
    void setmas(dlong af,dlong m1[]); // ������������� ����� 
};
void mastlong::setmas(dlong af,dlong m1[])
{ 
   int i;     
   if (af <= 10) size=af;  else size=10;
   for(i=0;i<size;i++)   mas[i].setnum(m1[i]);
}
void mastlong::printm()
{ 
    int  i;       
    printf("���������� ������� ������ \n");
    for(i=0;i<size;i++)   mas[i].print();
}
void main()
{  
    setlocale(0,"russian");
    int i,n; dlong mn[4]={456,5678,64328,45234},*mn2;
    mastlong a(4,mn);  
    a.printm();
    _getch(); 
}
