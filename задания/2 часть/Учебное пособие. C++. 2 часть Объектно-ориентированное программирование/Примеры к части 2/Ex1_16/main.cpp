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
        cout<<"C��������� ����� : "<< endl;
        cout<<"x= "<<x<<" y= "<<y<<"  str= "<<str<<endl;
    }
    sstr(){} // ������������������ �����������
    sstr(int vx,int vy,char *vs="C����� �� ���������")
    {  setstr(vx,vy,vs); }
    ~sstr() {} // ����������
    void setstr(int ax,int ay,char *vs); /* �������������
                                                                                                             ����� ������� */
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
    sstr  *a[5],  // ������ ���������� �� ���� ������������ ��������
           *c;    // ��������� �� ������ ������������ ��������
    int i,j;
    char *vs="������";   //�������� ������ � ���������������� ������ 
    for(int i=0;i<5;i++) // ������� ������ ������������ ��������         
       a[i]=new sstr(10+i,10+2*i,"aaaa"+i); 
    cout<<"  ������ �������� a"<<endl;
    for(i=0;i<5;i++) // ������� ���������� ����� ��������
    { 
        cout<<"������� "<< i+1; 
        a[i]->print();
    } 
    for(i=0;i<5;i++) delete a[i];      // ���������� ������ 
    c=new sstr[3];     // �������� ������ ��� ��� ������������ �������
    for(i=0;i<3;i++)   //  ���������������� ���� ������������ ��������
      (c+i)->setstr(15+i,12+i*2,vs+i); 
    cout<<"  ������ �������� c"<<endl;
    for(i=0;i<3;i++)  // ������� ���������� ����� ��������
    { 
       cout<<"������� "<< i+1;  
       (c+i)->print();
    } 
    delete []c; // ���������� ������
    system("pause");  
}
