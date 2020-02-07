#include <stdio.h>
class First
{ 
public:  
	char c;
	int x,y;
	/* компонентные функции, определенные внутри класса */
	void print(void)
	{  
		printf ("%c %d %d ",c,x,y);   
	}
	void set(char ach,int ax,int ay) 
	{ 
		c=ach;    x=ax;    y=ay;  
	}     
};
