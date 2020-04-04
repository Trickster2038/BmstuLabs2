// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	class CQueue {
	protected:
		vector<char> queuef;
		int lng;
		int p;
	public:
		void add(char arg) {
			queuef.push_back(arg);
		}
		void rm() {
			queuef.pop_back();
		}
		void setlng() {
			lng = 0;
			for (vector<char>::iterator i = queuef.begin(); i != queuef.end(); ++i) {
				lng++;
			}
		}
		int getlng() {
			return lng;
		}
		void reset() {
			p = -1;
		}
		char gett() {
			p++;
			return queuef[p];
		}
	};
	class CSmartQ : public CQueue {
	public:
		void sort() {
			bool sorted = false;
			while (!(sorted)) {
				sorted = true;
				for (vector<char>::iterator i = queuef.begin(); i != (queuef.end()-1); ++i) {
					if ((*i) > * (i + 1)) {
						char buf;
						buf = *i;
						*i = *(i + 1);
						*(i + 1) = buf;
						sorted = false;
					}
				}
			}
		}
	};

	CSmartQ q1;
	q1.add('5');
	q1.add('b');
	q1.add('a');
	q1.add('1');

	q1.reset();

	printf("%c",q1.gett());
	printf("%c", q1.gett());
	printf("%c", q1.gett());
	printf("%c", q1.gett());


	q1.sort();

	q1.reset();

	printf(" %c", q1.gett());
	printf("%c", q1.gett());
	printf("%c", q1.gett());
	printf("%c", q1.gett());
	q1.setlng();
	printf(" %d", q1.getlng());
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
