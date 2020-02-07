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
Point a;         // объявление объекта  
a.SetPoint(5,10); // инициализация полей
a.Print();        // вывод содержимого полей на экран

Point b(2,3);    // создание объекта  
b.Print();        // вывод содержимого полей на экран

Point *e;        // объявление неинициализированного указателя на объект
e=new Point(3,4); // выделение памяти и инициализация полей
e->Print();        // вывод содержимого полей на экран
delete e;          // освобождение памяти

Point *j=new Point(3,4); /* объявление указателя на объект, 
                                    выделение памяти и инициализация полей объекта */
j->Print();    // вывод содержимого полей на экран
delete j;              // освобождение памяти

Point c[4];              // объявление массива объектов  
for(int i=0;i<4;i++) 
{
    c[i].SetPoint(i*i,i-5); // инициализация полей
    c[i].Print();  // вывод содержимого полей на экран
}

Point d[2]= {Point(2,4),Point(4,5)}; /* создание массива 
                      объектов и инициализация их полей */
for(int i=0;i<2;i++) d[i].Print();// вывод содержимого полей на экран

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