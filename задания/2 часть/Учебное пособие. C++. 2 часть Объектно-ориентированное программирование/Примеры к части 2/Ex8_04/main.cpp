#include <iostream> 
#include <stdlib.h>
#include <conio.h>
#include <boost/weak_ptr.hpp>
#include <boost/shared_ptr.hpp>

using namespace std;
using namespace boost;

int main()
{
    shared_ptr<int> s1( new int(5) );   // ������� ������ -> 
	                                  //  ������� ������ = 1
	shared_ptr<int> s2 = s1; // ������� ������� ��������� -> 
	                       // ������� ������ = 2
	weak_ptr<int> w = s2;   // ������� ������ ��������� -> 
	                      // ������� ������ = 2   
	s2.reset();   // ����������� s2 -> 
	              // ������� ������ = 1 � ������ ����������
	s2 = w.lock(); // ��������� ������� ��������� � �������� ->
	               // ������� ������ = 2
	s2.reset();    // ����������� s2 ->  
	               // ������� ������ = 1
	s1.reset();  // ����������� s1 -> 
	             // ������� ������ = 0 -> ������ ���������
// �������� ������������� ������� (������ 1)
	s2 = w.lock();// �������� ������� ������� ��������� �� ������� ->
                  // s2 ����� 0, �.�. ������ �� ����������  
	if (w.expired())
		cout<<"Object is not exists..."<<endl;
	else cout<<"Object exists..."<<endl;
// �������� ������������� ������� (������ 2)
	if (s2.get() == 0)// �������� ����� ������� � ���������� � �����
		cout<<"Object is not exists..."<<endl;
	else cout<<"Object exists..."<<endl;
 
	getch();
}
