#include <iostream>

using namespace std;
typedef unsigned long dlong;
class Tlong            // ����� ����� �����
{ 
 public:           
     dlong num;        // �������� ���� ������ 
     Tlong(){}         // ������������������ �����������
     Tlong(dlong an):num(an){} // �����������
     ~Tlong(){}          // ����������
     void print(void)    // ����� �������� ����
     { cout<<" ����� ����� : "<<num<<endl; }
     void setnum(dlong an) // ������������� ���� 
     { num=an; }
     void show()  // �����, ���������� ���������������� ����� 
     { print(); }
};
