﻿// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int main()
{
	struct zap {
		char* content;
		zap* next;
	};
	char inp[50], buf[50], * cut, *buff;
	zap* q, * p, * st;

	st = new zap;
	p = st;
	(*p).next = NULL;
	gets_s(inp);
	cut = inp;
	int i = 0;
	while (inp[i] != '\0') {
		int j = 0;
		//(buf[0]) = new char[50];
		buff = new char[50];
		while (inp[i] == ' ') {
			i++;
		}
		while ((inp[i] != '\0') && (inp[i] != ' ')) {
			//buf[j] = inp[i];
			*(buff + j) = inp[i];
			i++;
			j++;
		}
			//buf[j] = '\0';
		*(buff + j) = '\0';
			puts(buff);
			//puts("|");
			//buff = new char[50];
			//*buff = *buf;
			q = new zap;
			//(*q).content = new char;
			//strcpy_s((*q).content,1, buff);
			(*q).content = buff;
			(*p).next = q;
			printf("addr1: %x \n", p);

			p = (*p).next;
			puts((*p).content);
			printf("addr2: %x \n", p);
			(*p).next = NULL;
			
			/*
			(*p).content = buf;
			(*p).next = new zap;
			p = (*p).next;
			(*p).content = NULL;
			*/
		
		
	}
	/*cut = strstr(cut, " ") + 1;
	puts(cut);
	q = new zap;
	*/
	//(inp[0]) = *cut;

	if (((*st).next != NULL)) {
		st = (*st).next;
	}

	p = st;

	while (p != NULL) {
		printf("addr3: %x addrf: %x \n", p, &((*p).content));
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
