// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
inline int vInput(int* ins);
inline int vMulti(int* ins);
inline int vSum(int* ins);
inline int vSub(int* ins);
inline int vEq(int* ins);
inline int vGood(int* a1, int* b1);

int main()
{
	int n = 73;
	int m;
	int x[2], y[2];
	x[0] = 0;
	x[1] = 0;
	puts("WARNING: X been set to [0,0] as default");
	while (n != 0) {
		puts("\n Choose action: \n 0) Exit \n 1) Input/reset \n 2) summation + \n 3) subtrction - \n 4) scalar * \n 5) equalence =");
		scanf_s("%d", &n);
		try {
			vGood(&n, &n);
		}
		catch (int excep) {
			puts("Anomaly input, please retry \n");
		}
		try {
			switch (n) {
			case 0:
				puts("exit...");
				break;
			case 1:
				vInput(&x[0]);
				break;
			case 2:
				vSum(&x[0]);
				break;
			case 3:
				vSub(&x[0]);
				break;
			case 4:
				vMulti(&x[0]);
				break;
			case 5:
				vEq(&x[0]);
				break;
			default:
				puts("Unknown operation id, please retry \n");
			}
		}
		catch (int excep) {
			puts("Anomaly input, please retry \n");
		}
		printf("Current X = [%d, %d] \n", x[0], x[1]);
	}
}

inline int vInput(int* ins) {
	int a, b;
	puts("Enter coords in formar %d %d");
	scanf_s("%d %d", &a, &b);
	vGood(&a, &b);
	*ins = a;
	*(ins + 1) = b;
	return 0;
}

inline int vMulti(int* ins) {
	int a;
	puts("Enter num to multiply");
	scanf_s("%d", &a);
	vGood(&a, &a);
	*ins = a * (*ins);
	*(ins + 1) = a * (*(ins + 1));
	return 0;
}

inline int vSum(int* ins) {
	int a, b;
	puts("Enter coords in formar %d %d");
	scanf_s("%d %d", &a, &b);
	vGood(&a, &b);
	*ins = a + (*ins);
	*(ins + 1) = b + (*(ins + 1));
	return 0;
}

inline int vSub(int* ins) {
	int a, b;
	puts("Enter coords in formar %d %d");
	scanf_s("%d %d", &a, &b);
	vGood(&a, &b);
	*ins = - a + (*ins);
	*(ins + 1) = - b + (*(ins + 1));
	return 0;
}

inline int vEq(int* ins) {
	int a, b;
	puts("Enter coords in formar %d %d");
	scanf_s("%d %d", &a, &b);
	vGood(&a, &b);
	if ((*ins == a)&&(*(ins+1)==b)) {
		puts("Vectors equal \n");
	}
	else {
		puts("Vectors dont equal \n");
	}
	return 0;
}

inline int vGood(int *a1, int *b1) {
	if ((*a1 > 10000) || (*a1 < -10000) || (*b1 > 10000) || (*b1 < -10000)) {
		throw(-1);
	}
	return 0;
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
