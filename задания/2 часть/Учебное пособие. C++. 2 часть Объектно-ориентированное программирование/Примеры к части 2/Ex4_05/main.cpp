#include <locale.h>
#include <iostream>
using namespace std;
class SHOW; // ���������� ������ ��� ��� �����������
class PAIR
{
 private:     char *Head,*Tail;
 public: 
     PAIR(char *one,char *two):Head(one),Tail(two){}
     friend class SHOW;  // ���������� �������������� ������
};
class SHOW   /* ���� �������� ������ SHOW �������� ���������� 
                                                                                         ���� ������ PAIR*/
{
 private:   PAIR Twins;
 public:    SHOW(char *one,char *two):Twins(one,two){}
     void Head() { cout <<Twins.PAIR::Head << endl; }
     void Tail() { cout <<Twins.PAIR::Tail << endl; }
};     
void main()
{
    setlocale(0,"russian");     
    SHOW aa("������","������");
    cout << "���������� ������:"<<endl;
    aa.Head();  // �������:  ������
    aa.Tail();  //  �������:  ������  
        system("pause"); 
}
