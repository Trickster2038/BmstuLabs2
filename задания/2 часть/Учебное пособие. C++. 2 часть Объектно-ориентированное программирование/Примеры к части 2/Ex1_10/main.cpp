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
         cout<<" ���: "<<name;  
         cout<<" ������� : "<<age<< endl;
     }
     child(char *Name,int Age):age(Age)
     {
         strcpy(name,Name);
     }
 };
void main()
{ 
    setlocale(0,"russian");
    child aa("�����",6);
    aa.print();    // �������:   ���: �����   �������: 6
    child bb=aa;   // �������� ���������� �����������
    bb.print();    // �������:   ���: �����   �������: 6
    system("pause");  
}

