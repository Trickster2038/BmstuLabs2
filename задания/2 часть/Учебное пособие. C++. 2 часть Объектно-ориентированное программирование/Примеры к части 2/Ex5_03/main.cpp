#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
typedef unsigned long dlong;
class Tlong
{
 public:     dlong   num;
     Tlong(){}
     Tlong(dlong an) { setnum(an);}
     friend ostream & operator <<(ostream &out,Tlong obj);
     friend istream & operator >>(istream & in,Tlong &obj);
     void print(void);
     void setnum(dlong an) { num=an;}
};
ostream & operator <<(ostream & out,Tlong obj)
{
    out<<" �������� ����� :   "<<obj.num<<endl;  
    return out;  
}
istream & operator >>(istream & in,Tlong &obj)
{  
    cout<<" �������  �����  "<<endl;  
    in>>obj.num;  
    return in;  
}
void Tlong::print()  
{   cout<<" ��������  ����� : "<<num<<endl; }
void main()
{ 
    setlocale(0,"russian");
    Tlong a,b;
    cout<<"���� �������� ����� ��������"<<endl;   
    cin>>a>>b;  
    cout<<"������� ������  a"<<a<<endl;     
    cout<<"������� ������  b"<<b<<endl;     
    system("pause"); 
}
