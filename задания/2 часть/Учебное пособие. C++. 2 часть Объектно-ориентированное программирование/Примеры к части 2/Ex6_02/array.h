#include <locale.h>
#include <stdio.h>
#include <iostream>
using namespace std;
template <class type>   // ���������� ������� � ���������� "type"          
class array                   
{     
    type * contents; // ��������� �� ������������ ������ ���� type
    int size;        // ������ �������
  public:
    array(int number) 
    {   contents = new type [size=number];}
    ~array ()  { delete [] contents;}   
    type & operator [] (int x)  // ��������������� ��������  [] 
    { 
        if ((x<0)||(x>=size))  
        { cerr << "��������� ������"; x=0;}
        return contents[x];  
    }
};
