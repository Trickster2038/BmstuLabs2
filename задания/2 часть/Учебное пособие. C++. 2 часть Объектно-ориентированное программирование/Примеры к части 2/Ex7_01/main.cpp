#include <stdlib.h>
#include <iostream>
using namespace std;
class E{};                        // ����� ����������
void somefunc(bool ccc) // �������, ������������ ����������
{ 
    if(ccc) throw E(); 
}  
void func()
{  
    try 
    {    somefunc(true);    }
    catch(E& e)
    {    
         /*���� ����� ���������� ���������� ������, �� ������������ ���*/  
         if (true) throw; 
    } 
}
void  main()
{  
     try   { func();   }
     catch(E& e)
	 { 
		 // ����� ������������ ���������� 
		 cout<<"Exception"<<endl;
	 }  
	 system("pause");
}  
