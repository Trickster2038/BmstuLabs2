// #include "pch.h"  только при создании проекта с заголовочными файлами (!)
#include <locale.h> // для подключения русского языка
#include <stdio.h>  // подключение процедур ввода вывода
#include "Nod.h"
/*
int nod(int x, int y)
{
	while (x != y)
		if (x > y) x = x - y;
		else y = y - x;
	return y;
}
*/
int main()
{
	int a, b;
	setlocale(0, "russian"); // подключение русского языка
	puts("Введите два натуральных числа:");
	scanf_s("%d %d", &a, &b);
	printf("НОД %d и %d = %d.\n", a, b, nod(a, b));
	return 0;
}