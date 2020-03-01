// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <set>
using namespace std;

int main()
{
	set <char> gl = { 'a','e','y','u','i','o','j' };
	struct zap {
		char* content;
		zap* next;
	};
	char inp[50], buf[50], * cut, * buff;
	zap* q, * p, * st, * st1;
	bool exist = false;

	st = new zap;
	p = st;
	(*p).next = NULL;
	puts(">>Input string: ");
	gets_s(inp);
	int i = 0;
	while (inp[i] != '\0') {
		int j = 0;

		buff = new char[50];
		// ATTENTION - if you forgot it - all list's elements will be addresed to one string

		while (inp[i] == ' ') {
			i++;
		}
		while ((inp[i] != '\0') && (inp[i] != ' ')) {
			*(buff + j) = inp[i];
			i++;
			j++;
		}
		*(buff + j) = '\0';
		q = new zap;
		(*q).content = buff;
		(*p).next = q;
		p = (*p).next;
		(*p).next = NULL;
	}


	if (((*st).next != NULL)) {

		puts(">>>list1:");
	}
	else {
		puts(">>>list1 is empty");
	}

	st = (*st).next;

	p = st;



	while (p != NULL) {
		puts((*p).content);
		p = (*p).next;
	}

	p = st;
	//q = NULL; 
	//st1 = NULL; 
	st1 = new zap;
	(*st1).next = NULL;
	q = st1;
	while (p != NULL) {
		if (gl.count((*p).content[0]) != 0) {
			q->next = new zap;
			q->next->content = p->content;
			q = q->next;
			q->next = NULL;
		}
		p = p->next;

	}

	if (((*st1).next != NULL)) {
		puts(">>>list2:");
	}
	else {
		puts(">>>list2 is empty");
	}
	st1 = (*st1).next;

	p = st1;

	while (p != NULL) {
		puts((*p).content);
		p = (*p).next;
	}


}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
