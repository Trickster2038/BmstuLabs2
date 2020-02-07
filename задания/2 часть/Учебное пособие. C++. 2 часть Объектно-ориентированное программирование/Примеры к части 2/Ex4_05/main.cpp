#include <locale.h>
#include <iostream>
using namespace std;
class SHOW; // объ€вление класса без его определени€
class PAIR
{
 private:     char *Head,*Tail;
 public: 
     PAIR(char *one,char *two):Head(one),Tail(two){}
     friend class SHOW;  // объ€вление дружественного класса
};
class SHOW   /* всем функци€м класса SHOW доступны внутренние 
                                                                                         пол€ класса PAIR*/
{
 private:   PAIR Twins;
 public:    SHOW(char *one,char *two):Twins(one,two){}
     void Head() { cout <<Twins.PAIR::Head << endl; }
     void Tail() { cout <<Twins.PAIR::Tail << endl; }
};     
void main()
{
    setlocale(0,"russian");     
    SHOW aa("ѕ–»¬≈“","ƒ–”«№я");
    cout << "–езультаты работы:"<<endl;
    aa.Head();  // выводит:  ѕ–»¬≈“
    aa.Tail();  //  выводит:  ƒ–”«№я  
        system("pause"); 
}
