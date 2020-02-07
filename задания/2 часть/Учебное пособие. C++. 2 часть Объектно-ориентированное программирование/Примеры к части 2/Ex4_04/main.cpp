#include <locale.h>
#include <iostream>
using namespace std;
class FLOAT; // ���������� ������ ��� ��� �����������
class FIXED
{ 
 private:    int a;
 public:     FIXED(int v):a(v){}
     double Add(FLOAT);
     void print(){cout <<a << endl;}
};
class FLOAT
{
 private:    double b;
 public:     FLOAT(double val) { b=val; }
       void print(){   cout <<b << endl;  }
       friend double FIXED::Add(FLOAT); /* ������������ ������� 
                                ������ FIXED ����������� ������������� ������ FLOAT */
};
double FIXED::Add(FLOAT Par)
{   return a+Par.b;  }   /* ������� �������� ������ � ����������� 
                                                                                       ���� ������ FLOAT */
void main()
{ 
    setlocale(0,"russian");
    FIXED aa(25); FLOAT bb(45);
    cout << "���������� ������: "<<endl;
    cout<<aa.Add(bb)<<endl;  // �������:  70
    aa.print();   // �������: 25
    bb.print();   // �������: 45
    system("pause"); 
}
