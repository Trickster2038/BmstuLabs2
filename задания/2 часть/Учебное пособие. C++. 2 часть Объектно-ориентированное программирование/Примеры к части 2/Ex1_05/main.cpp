#include <locale.h>
#include <iostream>
using namespace std;
class Num 
{
    int n;
 public: 
    Num(int an){  cout<<"Конструктор"<<endl; n=an;  }
    ~Num()     {  cout<<"Деструктор"<<endl;  }
};
void main(int argc, char* argv[])
{
    setlocale(0,"russian");
    Num N(56); 
    system("pause");
}
