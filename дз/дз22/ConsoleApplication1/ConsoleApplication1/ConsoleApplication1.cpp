﻿// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
    int n = 0;
    char* mstr[30];
    for (int i = 0; i < 30; i++) {
        mstr[i] = NULL;
    }
    char* p, * q,*tr,*st, *buf;
    buf = NULL;
    q = NULL;
    puts("Enter kol-vo of strings \n");
    scanf_s("%d", &n, 10);
    char* sp;
    sp = NULL;
    sp = new char;
    gets_s(sp,1);
    for (int i = 0;i < n;i++) {
        mstr[i] = new char[30];
        gets_s(mstr[i], 30);
    }
    puts("\n ECHO \n");
    for (int i = 0;i < n;i++) {
        printf("\n %s", mstr[i]);
    }
    puts("\n \n CCORRECTED \n");
    for (int i = 0;i < n;i++) {
        tr = mstr[i];
        while (tr != NULL) {
            p = strtok_s(tr, " ", &q);
            q = strtok_s(q, " ", &tr);
           if ((p == NULL) || (q == NULL)) {
                break;
            }
            st = tr;
            printf_s("%s %s ", q, q);
        }
        puts("\n");
        delete[] mstr[i];

        // delete
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
