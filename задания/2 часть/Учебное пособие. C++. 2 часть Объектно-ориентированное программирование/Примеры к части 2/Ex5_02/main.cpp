#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
typedef unsigned long dlong;
class Tlong
{
 public:      dlong   num;
    Tlong(){}
    Tlong(dlong an) { setnum(an);}
    friend Tlong & operator *(Tlong&,int k);
    friend Tlong & operator *(int k,Tlong&);
    void print(void);
    void setnum(dlong an) { num=an;}
};
Tlong & operator *(Tlong & ob1,int k)
{
    Tlong *temp=new Tlong;   
    temp->num=ob1.num*k; 
    return *temp;
}
Tlong & operator *(int k,Tlong &ob2)
{
    Tlong *temp=new Tlong;
    temp->num=ob2.num*k;
    return *temp; 
}
void Tlong::print()  
{   cout<<"Значение  числа : "<<num<<endl;}
Tlong a(424567),c,d;       long int  n;
void main()
{
    setlocale(0,"russian");
    d=a*2;      
    cout<<"d=a*2:"; d.print();
    c=operator *(2,a);      
    cout<<"с=2*a:"; c.print();
    system("pause"); 
}
