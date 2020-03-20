// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

int main()
{
	class CBread {
	protected:
		int m;
		int price;
	public:
		void sett(int argM, int argPrice) {
			m = argM;
			price = argPrice;
		}
		void get() {
			printf("\n massa: %d price: %d", m, price);
		}
		double cost() {
			return (price * 100.0) / (m * 1.0);
		}
		CBread() {
			m = 0;
			price = 0;
		}
	};
	class CBun : public CBread {
	protected:
		int ms;
	public:
		float mPart() {
			return (ms * 1.0) / (m);
		}
		void sett(int argM, int argMs, int argPrice) {
			CBread::sett(argM, argPrice);
			ms = argMs;
		}
		CBun() :CBread() {
			ms = 0;
		}
	};

	int a1, a2, a3;
	CBread bread;
	CBun bun;

	puts("Enter M and PRICE for bread");
	scanf_s("%d %d", &a1, &a2);
	bread.sett(a1, a2);
	bread.get();
	printf("\n cost for 100g: %3.2f", bread.cost());

	puts("\n \n Enter M and M OF FILLING and PRICE for bun");
	scanf_s("%d %d %d", &a1, &a2, &a3);
	bun.sett(a1, a2, a3);
	bun.get();
	printf("\n cost for 100g: %3.2f", bun.cost());
	printf("\n fillng mass part: %3.2f", bun.mPart());

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
