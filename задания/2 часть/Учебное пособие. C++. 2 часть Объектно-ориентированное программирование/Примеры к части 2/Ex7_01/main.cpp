#include <stdlib.h>
#include <iostream>
using namespace std;
class E{};                        // класс исключения
void somefunc(bool ccc) // функция, генерирующая исключение
{ 
    if(ccc) throw E(); 
}  
void func()
{  
    try 
    {    somefunc(true);    }
    catch(E& e)
    {    
         /*если здесь исключение обработать нельзя, то возобновляем его*/  
         if (true) throw; 
    } 
}
void  main()
{  
     try   { func();   }
     catch(E& e)
	 { 
		 // здесь обрабатываем исключение 
		 cout<<"Exception"<<endl;
	 }  
	 system("pause");
}  
