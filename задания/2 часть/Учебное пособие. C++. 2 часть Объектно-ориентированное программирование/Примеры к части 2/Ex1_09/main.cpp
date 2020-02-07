#include <locale.h>
#include <stdio.h>
#include <conio.h>
class Num 
{
    int n;
public: 
    Num(int an):n(an){} // инициализирующий конструктор 
    Num(){}             // неинициализирующий конструктор
    void setNum(int an){n=an;} // инициализирующий метод
};
void main()
{
    setlocale(0,"russian");
    int nn;
    Num A[5]; // неинициализированный массив
    for(int i=0;i<5;i++) // инициализаци€ элементов массива
    { 
        printf("¬ведите значение пол€ %d-го объекта:",i);
        scanf("%d",&nn);
        A[i].setNum(nn);
    }
          // инициализированный массив
    Num B[3]={Num(3),Num(8),Num(10)};  
    _getch();
}
