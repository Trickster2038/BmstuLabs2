#include <locale.h>
#include <string.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
template <class type> // объявление шаблона класса 
class arrayob         // класс Динамический массив
{ 
   type **contents;   // массив указателей на объекты типа type
   int size;          // максимальное количество объектов в массиве
   int n;             // реальное количество объектов в массиве
 public:
   arrayob(int number)  
   { contents=new type * [size=number];} 
   ~arrayob ();
   void add(type *p)
   {  
      if(n==size)cerr<<"Выход за пределы";   
      else {contents[n]=p; n++;} 
   }
   type & operator [] (int x)    //  итератор массива объектов  
   { 
      if ((x<0)||(x>=size)) 
      { cerr <<"Ошибочный индекс "<<x<<endl;x=0;}
      return *contents[x]; 
   }
   int sizeofmas(){return n;}  // реальный размер массива
};
template <class type> arrayob<type>::~arrayob ()  
{ 
   for(int i=0;i<size;i++) delete contents[i]; 
   delete []contents;
}
class TNum               // класс  Число
{
 public: 	int num;
    virtual void Print(void) { cout<<num<<" "; }
    TNum(){cout<<"Введите число"<<endl; cin>>num;}
    TNum(int n):num(n) {}
    virtual ~TNum(void){}
};
class TStr:public TNum   // класс Строка
{ 
 public:	 char *st;
    virtual void Print(void) { TNum::Print(); cout<<st<<" ";}
    TStr();    // конструктор по умолчанию
    TStr(char *s):TNum(strlen(s))// конструктор с параметрами
    {
        st=new char[num+1];    strcpy(st,s);  
        st[num]='\0';   
    }
    virtual ~TStr(void){ delete [] st;}
};
TStr::TStr():TNum(40)
{   
    cout<<"введите строку "<<endl;
    st=new char[num+1];   cin>>st;
    num=strlen(st);  st[num+1]='\0';    
}
arrayob<TNum>  ob_a(5); //массив из 5 указателей на объекты                                                                                         
void main()
{
    setlocale(0,"russian");
    int i;
    for(i=0;i<5;i++)    
       if (i/2*2==i) 
         ob_a.add(new TNum);   // добавить Число
    else ob_a.add(new TStr);   // добавить Строку                 
    cout<<"Содержимое контейнера "<<"\n";
    for (i=0;i<ob_a.sizeofmas();i++) 
       ob_a[i].Print();
    system("pause");
}
