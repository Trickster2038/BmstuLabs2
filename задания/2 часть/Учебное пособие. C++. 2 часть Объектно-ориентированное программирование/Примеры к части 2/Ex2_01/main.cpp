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
    A aa(10);      // ���������� ����������� ������ �
    B bb(10,100);  //���������� ����������� ������ �, � ����� � �
    C cc(10,100,1000); // ���������� ������������ ������� �, � � �
    aa.printa();     bb.printb();    cc.printc();        
    system("pause");
}               
