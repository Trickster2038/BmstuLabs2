#include <iostream>
using namespace std;
class obinteg
{    
 public:
    const int x,y;       // ����������� ���� 
    int &c;              // ��������� ����
    void print(void)      
    { 
         cout<<" x="<<x<<" y= "<<y<<" color="<<c<<endl;
    }
    obinteg(int vx,int vy,int &vc):
         x(vx),y(vy),c(vc){} /* ������������� ����� ��������������
                           � ���������� ���� ����������� ������  ������������� */
                     
};
void main()
{    
    int k=13;
    obinteg bb(40,100,k);    // ���������������� ������
    bb.print();
    system("pause");                  
}
