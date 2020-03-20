// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
	class CTaxi {
	protected:
		int num;
		int places;
		bool child;
		bool free;
	public:
		CTaxi() {
			num = 0;
			places = 0;
			child = false;
			free = false;
		}
		void sett(int a1, int a2, int a3, int a4) {
			num = a1;
			places = a2;
			child = (a3 != 0);
			free = (a4 != 0);
		}
		void gett() {
			printf("\n num: %d \n places: %d \n child: %s \n free: %s \n", num, places, child ? "yes" : "no", free ? "yes" : "no");
		}
		void take() {
			free = false;
		}
		void let() {
			free = true;
		}
		bool check(int a2, int a3) {
			return ((places >= a2) && ((child) || (a3 == 0)) && (free));
		}
		int getNum() {
			return num;
		}
		// + get_field()
	};

	class CPark {
	protected:
		CTaxi taxi[20];
		int n;
	public:
		CPark() {
			n = -1;
		}
		void add(int a1, int a2, int a3, int a4) {
			n++;
			taxi[n].sett(a1, a2, a3, a4);
		}
		void gett() {
			for (int i = 0; i <= n; i++) {
				taxi[i].gett();
			}
			if (n < 0) {
				puts("\n park is empty");
			}
		}
		void take(int target) {
			for (int i = 0; i <= n; i++) {
				if (taxi[i].getNum() == target) {
					taxi[i].take();
				}
			}
		}
		void let(int target) {
			for (int i = 0; i <= n; i++) {
				if (taxi[i].getNum() == target) {
					taxi[i].let();
				}
			}
		}
		int find(int a2, int a3) {
			int res = -1;
			for (int i = 0; i <= n; i++) {
				if (taxi[i].check(a2, a3)) {
					res = taxi[i].getNum();
					break; // safe?
				}
			}
			return res;
		}
	};
	CPark yataxi;
	int inp1, inp2, inp3, inp4;
	int code = 73;
	while (code != 0) {
		puts("\n Enter command \n 1) add taxi \n 2) show all info \n 3) make busy by num \n 4) make free by num \n 5) find taxi by places and child");
		scanf_s("%d", &code);
		switch (code) {
		case 0:
			puts("\n exit...");
			break;
		case 1:
			puts("\n enter num, places, childplace(0 - no, other - yes), free(0 - no, other - yes)");
			scanf_s("%d %d %d %d", &inp1, &inp2, &inp3, &inp4);
			yataxi.add(inp1, inp2, inp3, inp4);
			break;
		case 2:
			yataxi.gett();
			break;
		case 3:
			puts("\n Enter num");
			scanf_s("%d", &inp1);
			yataxi.take(inp1);
			break;
		case 4:
			puts("\n Enter num");
			scanf_s("%d", &inp1);
			yataxi.let(inp1);
			break;
		case 5:
			puts("\n Enter places and childplace(0 - no, other - yes)");
			scanf_s("%d %d", &inp1, &inp2);
			if (yataxi.find(inp1, inp2) == -1) {
				puts("\n no such taxi, we are very sorry");
			}
			else {
				printf("\n nice car for you: %d", yataxi.find(inp1, inp2));
			}
			break;
		default:
			puts("\n no such option, retry");
			break;
		}
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
