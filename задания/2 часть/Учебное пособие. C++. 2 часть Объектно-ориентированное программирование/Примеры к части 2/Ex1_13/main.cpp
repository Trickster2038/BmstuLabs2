#include <stdio.h>
#include <conio.h>
class TNum 
{ 
 public:	int *pn;  // ��������� ��� ������ ������������� ����
	TNum(int n)                         // ���������������� �����������
     {   pn=new int(n);  }
	TNum(const TNum &Obj) // ���������� �����������
     {   pn=new int(*Obj.pn);     }
	~TNum()               // ����������
     {   delete pn;  }
};
void Print(TNum b)         // ������������ � ���������� ��������
{  printf("%d ",*b.pn); }
void main()
{ 
    TNum A(1);
    Print(A);
    _getch();	 
}
