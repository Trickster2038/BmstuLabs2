#include <locale.h>
#include <iostream>
using namespace std;
class Num 
{
    int n;
 public: 
    Num(int an){  cout<<"�����������"<<endl; n=an;  }
    ~Num()     {  cout<<"����������"<<endl;  }
};
void main(int argc, char* argv[])
{
    setlocale(0,"russian");
    Num N(56); 
    system("pause");
}
