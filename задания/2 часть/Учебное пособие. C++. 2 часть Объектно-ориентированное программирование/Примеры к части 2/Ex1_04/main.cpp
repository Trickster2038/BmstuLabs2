#include <stdio.h>
#include <conio.h>
class TA
{   
    int x,y;
 public:       
    void print(void)  
    {   
		printf("x=%5d  y=%5d\n",x,y);   
	}
    TA *fun1() // возвращает указатель на объект, для которого вызывается
    {   
		x=y=100;  return this;   
	}                                        
    TA fun2()  // возвращает объект, для которого вызывается 
    {   
		x=y=200;  
		return *this;  
	}
};
void main()
{    
    TA aa;    
    aa.fun1()->print();        //  выводит: 100 100
    aa.fun2().print();         //  выводит:  200  200
    _getch();
}
