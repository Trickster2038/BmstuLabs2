#include <stdlib.h>
#include <windows.h> 
#include <iostream>
#include "exception.h"

using namespace std;

void func1()
{
	int *p;
	__try   
	{
		*p = 13;  // ������!!
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{ 
		// ������� ���������� Win32 � ���������� �++
		throw(MyException("Wrong adresing!"));  
	}
}
void func2()
{
	try
	{ 
		func1();
	}
	catch(const MyException& e)
	{ 
		cout<<e.msg()<<endl;
	}
}
void func()
{ 
	__try
	{
		func2();
	}
	__finally  { cout<<"Finally execution"<<endl; }
}

void main()
{
	func();
	system("pause");
}

