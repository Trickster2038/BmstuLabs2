#include <iostream> 
#include <stdlib.h>
#include <conio.h>
#include <boost/shared_ptr.hpp>

using namespace std;
using namespace boost;

class A
{ 
private:
	int num;
public:
	A(int Num):num(Num){cout<< "Object created..."<<endl;}
	~A(){cout<< "Object deleted..."<<endl;}
	void Print()
	{
		cout<<"num="<<num<<endl;
	}
};

void main()
{
	shared_ptr<A> ptr_obj(new A(5)); // �������� ������� � ��������� 
	{ // ����� ����
		shared_ptr<A> ptr1 = ptr_obj; // ����������� ��������� 
        ptr1->Print();                                                                         // �� ������
		shared_ptr<A> ptr2 = ptr_obj;// ������ ����������� 
                                  // ��������� �� ��� �� ������
		ptr2->Print(); 
		ptr_obj.reset(); // ����������� �������� ���������
	} // ����� ������ ��������� ���������

	getch();
}
