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
	auto_ptr<A> temp1; // неинициализированный объект-указатель
	auto_ptr<A> temp(new A(1)); // инициализированный объект-указатель
	A &a= *temp; // ссылка на хранимый объект 
	cout<<"A.x="<<a.x<<endl;
	A *ptr = temp.get();// указатель на хранимый объект 
	cout<<"ptr="<<ptr<<endl;
     temp.reset(); // освобождение указателя 
	A *ptr1 = temp.get();// указатель на хранимый объект 
	cout<<"ptr1="<<ptr1<<endl;
	getch();
}
