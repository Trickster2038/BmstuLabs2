#include <locale.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
class Tpole  // ����������� �����  ����
{ 
 public:   
    Tpole() {}
    virtual void Print(void)=0; // ����������� �������
};
class Tnumpole:public Tpole     // ����� �����
{ 
 private: int num;
 public:
    Tnumpole(int n):num(n){}
    void Print(void)   /* ������ ����������� �������*/
    {   printf("����� =  %5d\n",num);  }
};
class Tstrpole:public Tpole    // ����� ������
{ 
 private: char str[10];
 public :
    Tstrpole(char *st) {  strcpy(str,st);  }
    void Print(void)   /* ������ �����������  �������*/
    {   printf("������ = %s\n",str);  }
};
void main()
{ 
    setlocale(0,"russian");
    int n,i; char st[80];
    Tpole *a[10];  // ������ ���������� �� ������� ������ Tpole
    for(i=0;i<10;i++)
    { 
       printf("\n������� ����� ����� ��� ������: ");
       scanf_s("%s",st,80);
       if ((n=atoi(st))!=0||
                (strlen(st)==1 && st[0]=='0'))
           a[i]=new Tnumpole(n); // �����
       else
           a[i]=new Tstrpole(st); // ������
    }
    for(i=0;i<10;i++)  a[i]->Print(); 
    for(i=0;i<10;i++) delete a[i]; 
    _getch();
}
