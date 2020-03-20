// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
	class CA {
	protected: int s;
		   int perc;
	public:
		void set(int argS, int argPerc) {
			s = argS;
			perc = argPerc;
		}
		void get() {
			printf("\n square: %d \n percent occupied: %d %%", s, perc);
		}
		float fspace() {
			return (s - (s * (perc / 100.0)));
		}
	};
	class CB : public CA {
	public:
		CB(int argS, int argPerc) {
			s = argS;
			perc = argPerc;
		}
		CB() {
			s = 0;
			perc = 100;
		}
	};

	int x1, y1, x2, y2;
	CA a;
	//CB b1();

	puts("Enter squareA, percentA, squareB, percentB");
	scanf_s("%d %d %d %d", &x1, &y1, &x2, &y2);

	puts("\n >>> for a:");
	a.set(x1, y1);
	a.get();
	printf("\n free space: %3.2f", a.fspace());

	puts("\n \n >>> for b:");
	CB b1(x2, y2);
	b1.get();
	printf("\n free space: %3.2f", b1.fspace());
	

	puts("\n \n press any key");
	_getch();

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
