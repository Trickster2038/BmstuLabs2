// #include "pch.h"  ������ ��� �������� ������� � ������������� ������� (!)
#include <locale.h> // ��� ����������� �������� �����
#include <stdio.h>  // ����������� �������� ����� ������
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
	setlocale(0, "russian"); // ����������� �������� �����
	puts("������� ��� ����������� �����:");
	scanf_s("%d %d", &a, &b);
	printf("��� %d � %d = %d.\n", a, b, nod(a, b));
	return 0;
}