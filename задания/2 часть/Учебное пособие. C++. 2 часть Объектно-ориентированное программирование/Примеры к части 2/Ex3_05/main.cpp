#include <iostream>
class A 
{
public:
    virtual ~A(){}/* ����� ����������� ������ ��������
                                        ����������� �����, ��� ��� ��� ����������
                                        ���������� ��������� RTTI*/
};
class B: public A 
{ 
public:
     virtual ~B(){}
};
void func(A& a)   /* �������, ���������� � ����������� ��������*/
{ 
     B& b=dynamic_cast<B&>(a); // ���������� ���������� �����  
}
void main()
{  
     B b;
     func(b);             //  ����� ������� � ����������� ��������
     system("pause");
}

