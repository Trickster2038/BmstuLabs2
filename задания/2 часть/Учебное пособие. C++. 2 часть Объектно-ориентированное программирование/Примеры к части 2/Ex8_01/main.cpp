#include <memory>
#include <iostream>
#include <conio.h>
using namespace std;
class A
{
public:	
	int x;
	A(int X):x(X){}
	A(){}
	~A(){cout<<"destructor"<<endl;}
};
void main()
{
	auto_ptr<A> temp1; // �������������������� ������-���������
	auto_ptr<A> temp(new A(1)); // ������������������ ������-���������
	A &a= *temp; // ������ �� �������� ������ 
	cout<<"A.x="<<a.x<<endl;
	A *ptr = temp.get();// ��������� �� �������� ������ 
	cout<<"ptr="<<ptr<<endl;
     temp.reset(); // ������������ ��������� 
	A *ptr1 = temp.get();// ��������� �� �������� ������ 
	cout<<"ptr1="<<ptr1<<endl;
	getch();
}
