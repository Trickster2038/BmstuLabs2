#include <locale.h>
#include <iostream>
using namespace std;
class Num
{    
    int n;
 public:
    Num(int an):n(an){} // ���������������� �����������
    Num(const Num& ob) // ���������� �����������
    {  n = ob.n*3; }
    void print(void)    
    { cout<<" ���� n ="<<n<<"  "<< endl; }
};
void main()
{  
    setlocale(0,"russian");
    Num aa(10);      // ���������� ���������������� �����������
    aa.print();      // ������� ���� n = 10
    Num bb=aa;       // ���������� ���������� �����������
    bb.print();      // ������� ���� n = 30
    system("pause");  
}
