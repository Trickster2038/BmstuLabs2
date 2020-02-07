#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <locale.h>
class TElement      // абстрактный класс Элемент списка
{ 
 public: TElement *pre,*suc;
    TElement(void) { pre=suc=NULL;}  // конструктор
    virtual void Print(void)=0;  // абстрактный метод вывода
};

class TNum: public TElement  //  класс Число
{
 public:  int num;       // числовое поле целого типа
    virtual void Print(void) { printf("%d ",num); }
    TNum(){}        // конструктор по умолчанию
    TNum(int n):num(n) {}      // конструктор
};

class TStr: public TNum   // класс Строка (num - длина строки)
{ 
 public:   char st[40];    // поле символьная строка
    TStr(){}        // конструктор по умолчанию
    TStr(char *s):TNum(strlen(s))
    {
        strcpy(st,s); 
        if (num>=40)st[40]='\0'; else st[num+1]='\0';
    }
    virtual void Print(void) 
    {   TNum::Print(); printf("%s\n",st);  }
};
class TTabl: public TStr // класс Таблица - добавляет строку
{
 public:    char str[20];
    virtual void Print(void) 
    {  TStr::Print();  printf("%s\n  ",str); }
    TTabl(){}   // конструктор по умолчанию
    TTabl(char *s,char *s2):TStr(s)
    {
        strcpy(str,s2);
        if (strlen(s2)>=20) str[20]='\0';  
        else str[strlen(s2)+1]='\0'; 
     }
};


class TSpisok        // класс Список
{
 protected: TElement *first,*last,*cur;  
 public:
     TSpisok(void){ first=last=cur=NULL;} // конструктор
     ~TSpisok();   // деструктор
     void Add(TElement *e); // добавление элемента в список
	TElement *Del(void);  // удаление элемента из списка
     // функции-итераторы
	TElement * ifirst()  // указатель на первый элемент
	{    return cur=first; }
	TElement * inext()   // указатель на следующий элемент
	{    return cur=cur->suc; }
};
TSpisok::~TSpisok()
{
     while ((cur=Del())!=NULL)  
     { cur->Print();   delete(cur); }    
}
void TSpisok::Add(TElement *e)
{
    if (first==NULL)  first=last=e;
    else {   e->suc=first; first=first->pre=e;}  
}
TElement *TSpisok::Del(void)
{ 
    TElement *temp=last;
    if (last!=NULL) 
    { 
        last=last->pre;  
        if (last!=NULL) last->suc=NULL; 
    }
    if (last==NULL) first=NULL;    
    return temp;   
}

TSpisok N;     // объявление объекта класса Список
void main(void)
{
	setlocale(0,"russian");
    int k;  char str[40];  char str2[20];
    TElement *p;
    // цикл формирования списка из элементов классов TNum, TStr, TTabl
    while(printf("Введите число:"), scanf("%d",&k)!=EOF)
    { 
        p=new TNum(k);     N.Add(p);
        printf("Введите строку:");    scanf("%s",str);
        printf("Введите строку 2:");  scanf("%s",str2);
        p=new TTabl(str,str2);     N.Add(p);
        printf("Введите строку:");    scanf("%s",str);
        p=new TStr(str);           N.Add(p); 
    }
    puts("\nВведены элементы:");
        // цикл обработки каждого элемента списка с помощью итераторов
    p=N.ifirst();
    while (p!=NULL) 
    {    p->Print();   p=N.inext();  } 
    _getch();
}
