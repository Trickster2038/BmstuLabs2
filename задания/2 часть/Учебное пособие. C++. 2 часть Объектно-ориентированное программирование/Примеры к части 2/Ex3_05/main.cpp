#include <iostream>
class A 
{
public:
    virtual ~A(){}/* класс обязательно должен включать
                                        виртуальный метод, так как для выполнения
                                        приведения требуется RTTI*/
};
class B: public A 
{ 
public:
     virtual ~B(){}
};
void func(A& a)   /* функция, работающая с полиморфным объектом*/
{ 
     B& b=dynamic_cast<B&>(a); // нисходящее приведение типов  
}
void main()
{  
     B b;
     func(b);             //  вызов функции с полиморфным объектом
     system("pause");
}

