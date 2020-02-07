#include <locale.h>
#include <iostream>
#include <iomanip>
using namespace std;
class TVector
{ 
 private:    int x,y,z;
 public:
    TVector(){} // ������������������ �����������
    TVector(int ax,int ay,int az) // ���������������� �����������
    {  x=ax;y=ay;z=az; }
    ~TVector(){} // ����������
    void PrintVec();
    void SetVec(int ax,int ay,int az) // ���������������� �����
    {  x=ax;y=ay;z=az; }
};
void TVector::PrintVec()
{ 
    cout<<"�������� �������: "<<setw(5)<<x<<" , ";
    cout<<setw(5)<<y<<" , "<<setw(5)<<z<<"\n";    
}
void main()
{
    setlocale(0,"russian");
    TVector *a,*b; //  ��� ��������� �� ������� ������
         // �������� ������ ��� ������������ ������� ������ 
    a=new TVector(12,34,23); // ������������������ ������
    b=new TVector;      // �������������������� ������
    b->SetVec(10,45,56); // ������������� �������
    a->PrintVec();    //  �������: 12,  34,  23
    b->PrintVec();    //  �������: 10,  45,  56
    // ����������� ������, ���������� ��� ������������ ������� ������ 
    delete a;         // �������� ����������
    delete b;         // �������� ����������
    system("pause");  
}
