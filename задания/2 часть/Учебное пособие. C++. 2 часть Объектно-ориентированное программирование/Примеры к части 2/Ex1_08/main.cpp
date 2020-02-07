#include <iostream>
using namespace std;
class obinteg
{    
 public:
    const int x,y;       // константные поля 
    int &c;              // ссылочное поле
    void print(void)      
    { 
         cout<<" x="<<x<<" y= "<<y<<" color="<<c<<endl;
    }
    obinteg(int vx,int vy,int &vc):
         x(vx),y(vy),c(vc){} /* инициализация полей фиксированного
                           и ссылочного типа посредством списка  инициализации */
                     
};
void main()
{    
    int k=13;
    obinteg bb(40,100,k);    // инициализируемый объект
    bb.print();
    system("pause");                  
}
