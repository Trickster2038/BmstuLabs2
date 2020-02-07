#include <iostream>
using namespace std;
class A
{ 
 private:       int x;
 protected:     int y;
 public:        int z;
     void print(void)
     { 
          cout<<"x = "<<x<<endl;
          cout<<"y = "<<y<<endl;
          cout<<"z = "<<z<<endl;
     }
     A(){x=20; y=30; z=50;}
 };
class B: private A   // ��� ���������� ������ A �� �������� � ������ B
{ 
  protected: A::y; /* ���������� ���� ������ A, 
                                   ����������� ��������� � ������ B */
  public:    A::z; /* ����� ���� ������ A, 
                                   ����������� ��������� � ������ B */
     B():A(){}
     void print(void)
     { 
        cout<<"y = "<<y<<endl;
        cout<<"z = "<<z<<endl;
     }
   };
void main()
{  
    A aa; // �������� ������� �������� ������
    B bb; // �������� ������� ������������ ������
    aa.print();   // �������:  x = 20  y = 30  z = 50
    bb.print();   // �������:  y = 30  z = 50
    system("pause");
}
