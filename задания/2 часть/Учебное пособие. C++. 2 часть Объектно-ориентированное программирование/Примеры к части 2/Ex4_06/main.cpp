#include "Object.h"
#include <stdlib.h>
void main()
{
	B b;
    b.func('c');   // �����  A::func(), ��� ��� �������� - ������
    b.func("c");   // �����  B::func(), ��� ��� �������� - ������ 
    system("pause");
}