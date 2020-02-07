#include "Object.h"
#include <stdio.h>

void A::func(char ch)  // метод базового класса
{ puts("Symbol"); }
void B::func(char *str) // метод производного класса
{ puts("String"); }

