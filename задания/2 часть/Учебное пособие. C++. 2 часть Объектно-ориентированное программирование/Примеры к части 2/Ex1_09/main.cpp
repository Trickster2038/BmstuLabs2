#include <locale.h>
#include <stdio.h>
#include <conio.h>
class Num 
{
    int n;
public: 
    Num(int an):n(an){} // ���������������� ����������� 
    Num(){}             // ������������������ �����������
    void setNum(int an){n=an;} // ���������������� �����
};
void main()
{
    setlocale(0,"russian");
    int nn;
    Num A[5]; // �������������������� ������
    for(int i=0;i<5;i++) // ������������� ��������� �������
    { 
        printf("������� �������� ���� %d-�� �������:",i);
        scanf("%d",&nn);
        A[i].setNum(nn);
    }
          // ������������������ ������
    Num B[3]={Num(3),Num(8),Num(10)};  
    _getch();
}
