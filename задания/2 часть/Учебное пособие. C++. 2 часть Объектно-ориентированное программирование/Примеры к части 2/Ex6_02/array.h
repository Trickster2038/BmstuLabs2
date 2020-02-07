#include <locale.h>
#include <stdio.h>
#include <iostream>
using namespace std;
template <class type>   // объявление шаблона с аргументом "type"          
class array                   
{     
    type * contents; // указатель на динамический массив типа type
    int size;        // размер массива
  public:
    array(int number) 
    {   contents = new type [size=number];}
    ~array ()  { delete [] contents;}   
    type & operator [] (int x)  // переопределение операции  [] 
    { 
        if ((x<0)||(x>=size))  
        { cerr << "ошибочный индекс"; x=0;}
        return contents[x];  
    }
};
