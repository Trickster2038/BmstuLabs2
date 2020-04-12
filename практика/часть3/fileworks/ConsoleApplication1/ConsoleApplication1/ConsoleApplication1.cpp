// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

struct comp {
    int ptype;
    int ram;
    int hdd;
    int cost;
};

class CBase {
public:
    //FILE* f;
    // void sort()
    void push(int a1, int a2, int a3, int a4) {
        comp buf;
        buf.ptype = a1;
        buf.ram = a2;
        buf.hdd = a3;
        buf.cost = a4;
        FILE* f;
        fopen_s(&f,"base.dat", "a+b");
        fwrite(&buf, sizeof(buf), 1, f);
        fclose(f);
    }
    bool gett(FILE *f1, int *a1, int *a2, int *a3, int *a4) {
        //bool ok;
        comp buf;
        //FILE* f;
        //f = fopen("base.dat", "r+b");
        if (!feof(f1)) {
            fread(&buf, sizeof(buf), 1, f1);
        }
        if (!feof(f1)) {
            *a1 = buf.ptype;
            *a2 = buf.ram;
            *a3 = buf.hdd;
            *a4 = buf.cost;
        }
        //fclose(f);
        return feof(f1);
    }
    void getmm(int* a1, int* a2, int* a3, int* a4) {
        int minc, maxc, minh, maxh, p1, p2, p3, p4;
        bool notall;
        FILE* f;
        fopen_s(&f,"base.dat", "r+b");
        rewind(f);
        notall = gett(f, &p1, &p2, &p3, &p4);
        minc = p4;
        maxc = p4;
        minh = p3;
        maxh = p3;
        while (notall)
        {
            notall = gett(f, &p1, &p2, &p3, &p4);
            if (notall) {
                if (p4<minc) {
                    minc = p4;
                }
                if (p4>maxc) {
                    maxc = p4;
                }
                if (p3<minh) {
                    minh = p3;
                }
                if (p3>maxh) {
                    maxh = p3;
                }
            }
        }
        *a1 = minc;
        *a2 = maxc;
        *a3 = minh;
        *a4 = maxh;
        //code
        fclose(f);
    }
};

int main()
{
    CBase ex1;
    ex1.push(1, 5, 3, 4);
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
