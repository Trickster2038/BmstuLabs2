#include <locale.h>
#include <iostream>
using namespace std;
class FIXED
{
 private:     int a;
 public:      FIXED(int v):a(v){}
     friend void show(FIXED);
};
void show(FIXED Par) 
{ 
    cout<<Par.a<<endl; // ������� ����� ������ � ����������� ���� a
    Par.a+=10;  
    cout<<Par.a<<endl;    
}
void main()
{  
    setlocale(0,"russian");
    FIXED aa(25);
    cout << "���������� ������: "<<endl;
    show(aa);  // �������:  25    35
    system("pause"); 
}
