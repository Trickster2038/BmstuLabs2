#include <iostream> 
#include <stdlib.h>
#include <conio.h>
#include <boost/weak_ptr.hpp>
#include <boost/shared_ptr.hpp>

using namespace std;
using namespace boost;

int main()
{
    shared_ptr<int> s1( new int(5) );   // создаем объект -> 
	                                  //  счетчик ссылок = 1
	shared_ptr<int> s2 = s1; // создаем сильный указатель -> 
	                       // счетчик ссылок = 2
	weak_ptr<int> w = s2;   // создаем слабый указатель -> 
	                      // счетчик ссылок = 2   
	s2.reset();   // освобождаем s2 -> 
	              // счетчик ссылок = 1 и объект существует
	s2 = w.lock(); // связываем сильный указатель с объектом ->
	               // счетчик ссылок = 2
	s2.reset();    // освобождаем s2 ->  
	               // счетчик ссылок = 1
	s1.reset();  // освобождаем s1 -> 
	             // счетчик ссылок = 0 -> объект уничтожен
// проверка существования объекта (способ 1)
	s2 = w.lock();// пытаемся создать сильный указатель из слабого ->
                  // s2 равен 0, т.к. объект не существует  
	if (w.expired())
		cout<<"Object is not exists..."<<endl;
	else cout<<"Object exists..."<<endl;
// проверка существования объекта (способ 2)
	if (s2.get() == 0)// получаем адрес объекта и сравниваем с нулем
		cout<<"Object is not exists..."<<endl;
	else cout<<"Object exists..."<<endl;
 
	getch();
}
