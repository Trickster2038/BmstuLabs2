#include <iostream>
class Point
{ 
 private: int x,y;
 public:  Point(){}
	Point(int ax,int ay): x(ax),y(ay){}
	void SetPoint(int ax,int ay){  x=ax; y=ay;  }
	void Print(){  std::cout<<x<<" "<<y<<"\n";  }
};

void main()
{
Point a;         // ���������� �������  
a.SetPoint(5,10); // ������������� �����
a.Print();        // ����� ����������� ����� �� �����

Point b(2,3);    // �������� �������  
b.Print();        // ����� ����������� ����� �� �����

Point *e;        // ���������� ��������������������� ��������� �� ������
e=new Point(3,4); // ��������� ������ � ������������� �����
e->Print();        // ����� ����������� ����� �� �����
delete e;          // ������������ ������

Point *j=new Point(3,4); /* ���������� ��������� �� ������, 
                                    ��������� ������ � ������������� ����� ������� */
j->Print();    // ����� ����������� ����� �� �����
delete j;              // ������������ ������

Point c[4];              // ���������� ������� ��������  
for(int i=0;i<4;i++) 
{
    c[i].SetPoint(i*i,i-5); // ������������� �����
    c[i].Print();  // ����� ����������� ����� �� �����
}

Point d[2]= {Point(2,4),Point(4,5)}; /* �������� ������� 
                      �������� � ������������� �� ����� */
for(int i=0;i<2;i++) d[i].Print();// ����� ����������� ����� �� �����

Point *m=new Point[3];
for(int i=0;i<3;i++) 
{
    m[i].SetPoint(i,i+1); 
    m[i].Print();
}   
delete [] m;

Point *s[3];                    
for(int i=0;i<3;i++) 
{
    s[i]=new Point(i,i+1); 
    s[i]->Print();
}
for(int i=0;i<3;i++) delete s[i];

Point *q[]={new Point(2,7),new Point(1,5),new Point(4,2)};                    
for(int i=0;i<3;i++) 
{
    q[i]->Print();
}
for(int i=0;i<3;i++) delete q[i];


system("pause");
}