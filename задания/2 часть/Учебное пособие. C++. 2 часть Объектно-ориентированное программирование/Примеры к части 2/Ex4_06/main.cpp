#include "Object.h"
#include <stdlib.h>
void main()
{
	B b;
    b.func('c');   // вызов  A::func(), так как параметр - символ
    b.func("c");   // вызов  B::func(), так как параметр - строка 
    system("pause");
}