#ifndef FWORK_H_
#define FWORK_H_
#include <iostream>
#include <QDebug>
#include <QFile>
#include <QDataStream>

// struct comp {
//     int ptype;
//     int ram;
//     int hdd;
//     int cost;
// };

class CBase {
public:
    //FILE* f;
    // void sort()
    void push(int a1, int a2, int a3, int a4);
    bool gett(FILE *f1, int *a1, int *a2, int *a3, int *a4);
    void getmm(int* a1, int* a2, int* a3, int* a4);
};

#endif