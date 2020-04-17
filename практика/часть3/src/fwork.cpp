// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include "fwork.h"

struct comp {
    int ptype;
    int ram;
    int hdd;
    int cost;
};

    void CBase::push(int a1, int a2, int a3, int a4) {
        qDebug()<<2;
        comp buf;
        buf.ptype = a1;
        buf.ram = a2;
        buf.hdd = a3;
        buf.cost = a4;
        FILE* f;
        fopen_s(&f,"base.dat", "a+b");
        fwrite(&buf, sizeof(buf), 1, f);
        fclose(f);
        qDebug()<<3;
    }
    // void CBase::push(int a1, int a2, int a3, int a4) {
    //     QFile *f=new QFile("qbase.dat");
    //     f->open(QFile::ReadWrite);
    //     f->seek(f->size());
    //     QDataStream out(f);
    //     out<<a1<<a2<<a3<<a4;
    //     f->close();
    // };

    bool CBase::gett(FILE *f1, int *a1, int *a2, int *a3, int *a4) {
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
        return !(feof(f1));
    }
    void CBase::getmm(int* a1, int* a2, int* a3, int* a4) {
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

    void CBase::deletee(int a1, int a2, int a3, int a4) {
        bool notall;
        int p1, p2, p3, p4;
        FILE* f,*fcopy;
        fopen_s(&f,"base.dat", "r+b");
        fopen_s(&fcopy,"basecopy.dat", "w+b");
        rewind(f);
        notall = gett(f, &p1, &p2, &p3, &p4);
        comp buf;

        while (notall)
        {
            if(!((p1==a1)&&(p2==a2)&&(p3==a3)&&(p4==a4))){
                buf.ptype = p1;
                buf.ram = p2;
                buf.hdd = p3;
                buf.cost = p4;
                fwrite(&buf, sizeof(buf), 1, fcopy);
            }
            notall = gett(f, &p1, &p2, &p3, &p4);
        }
        fclose(f);
        fopen_s(&f,"base.dat", "w+b");
        rewind(fcopy);
        notall = gett(fcopy, &p1, &p2, &p3, &p4);
        while (notall)
        {
            buf.ptype = p1;
            buf.ram = p2;
            buf.hdd = p3;
            buf.cost = p4;
            fwrite(&buf, sizeof(buf), 1, f);
            notall = gett(fcopy, &p1, &p2, &p3, &p4);
        }
        fclose(f);
        fclose(fcopy);
    }

    // void CBase::sort(){
    //     comp buf0,buf1,buf2;
    //     int p1,p2,p3,p4;
    //     bool notall, sorted;
    //     FILE* f;
    //     sorted = false;
    //     while(!sorted){
    //         sorted = true;
    //         fopen_s(&f,"base.dat", "r+b");
    //     rewind(f);
    //     notall = gett(f, &p1, &p2, &p3, &p4);
    //     buf1.ptype = p1;
    //     buf1.ram = p2;
    //     buf1.hdd = p3;
    //     buf1.cost = p4;     
    //     while (notall)
    //     {
            
    //         notall = gett(f, &p1, &p2, &p3, &p4);
    //         buf2.ptype = p1;
    //         buf2.ram = p2;
    //         buf2.hdd = p3;
    //         buf2.cost = p4;

    //         if(buf2.hdd<buf1.hdd){
    //             fseek(f,sizeof(buf1)*(-2), SEEK_CUR);
    //             fwrite(&buf2, sizeof(buf2), 1, f);
    //             fwrite(&buf2, sizeof(buf2), 1, f);
    //             sorted = false;
    //         }

    //         buf1.ptype = buf2.ptype;
    //         buf1.ram = buf2.ram;
    //         buf1.hdd = buf2.hdd ;
    //         buf1.cost = buf2.cost;
    //     }
    //     fclose(f);
    // }
    // }
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
