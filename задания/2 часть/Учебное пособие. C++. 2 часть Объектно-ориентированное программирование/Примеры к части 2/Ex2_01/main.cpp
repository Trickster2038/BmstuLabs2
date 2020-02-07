#include <iostream>
using namespace std;
class A   
{    
 public:   int a;
    A(int v):a(v){}    
    void printa(){   cout<<a<<endl;  }
  };
class B: public A
{     
 public:   int b;
    B(int va,int vb):A(va),b(vb) {} 
    void printb(void) {  cout<<a<<" "<<b<<endl;  }
};
class C: public B
 { 
  public:   int c;
      C(int va,int vb,int vc):B(va,vb),c(vc) {} 
      void printc(void) 
      {  cout<<a<<"  "<<b<<"  "<<c<<endl;  }
};
void main()
{ 
    A aa(10);      // вызывается конструктор класса А
    B bb(10,100);  //вызывается конструктор класса А, а затем – В
    C cc(10,100,1000); // вызываются конструкторы классов А, В и С
    aa.printa();     bb.printb();    cc.printc();        
    system("pause");
}               
