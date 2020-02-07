#include <stdio.h>
#include <conio.h>
class TNum 
{ 
 public:	int *pn;  // указатель для адреса динамического поля
	TNum(int n)                         // инициализирующий конструктор
     {   pn=new int(n);  }
	TNum(const TNum &Obj) // копирующий конструктор
     {   pn=new int(*Obj.pn);     }
	~TNum()               // деструктор
     {   delete pn;  }
};
void Print(TNum b)         // подпрограмма с параметром объектом
{  printf("%d ",*b.pn); }
void main()
{ 
    TNum A(1);
    Print(A);
    _getch();	 
}
