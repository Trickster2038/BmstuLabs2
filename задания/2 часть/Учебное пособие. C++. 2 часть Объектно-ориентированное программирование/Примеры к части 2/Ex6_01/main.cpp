#include <locale.h>
#include <conio.h>
#include <string.h>
#include <iostream>
using namespace std;

template <class  T> T maxx(T x, T y)
{   return(x>y)?x:y;  }

char * maxx(char * x,char * y) // функция для объектов типа "строка" 
{   return strcmp(x,y)>0?x:y;  }


void main ()
{
 	setlocale(0,"russian");
    int a=1,b=2;      
	char c='a',d='m';      
    float e=123.67,f=456.67;
    char str[]="abcd", str2[]="abnd";
         // вызов функции для объектов различного типа
    cout << "Integer max= "<<maxx(a,b)<< endl;  
    cout << "Character max= "<<maxx(c,d)<< endl; 
    cout << "Float max=    "<<maxx(e,f)<< endl;        
    cout << "String max=   "<<maxx(str,str2)<< endl;  
    system("pause"); 
}
