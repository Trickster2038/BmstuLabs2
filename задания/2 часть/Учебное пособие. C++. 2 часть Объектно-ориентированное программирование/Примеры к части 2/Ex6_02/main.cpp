#include "array.h"
#include <stdlib.h>
#include <time.h>
void main()
{ 
    setlocale(0,"russian");
    int i;
    srand( (unsigned)time( NULL ) );
    array<int> int_a(5);
    array<char>  char_a(5);
    for (i=0;i<5;i++)     //  определение компонент массивов
    {   int_a[i]=rand()/1000+10;  char_a[i]='A'+i;}
    puts("Компоненты массивов");
    for (i=0;i<5;i++)
    {   cout << "   "<< int_a[i]<< "  " <<char_a[i]<<endl;}
    system("pause"); 
}

