#include <locale.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
class TElement      // абстрактный класс Элемент списка
{ 
 public: TElement *pre,*suc;
    TElement(void) { pre=suc=NULL;}  // конструктор
    virtual void Print(void)=0;  // абстрактный метод вывода
};
class TSpisok        // класс Cписок
{
 protected: TElement *first,*last,*cur; /*указатели на первый,
                                                     последний и текущий элементы списка */
 public:  TSpisok(void){ first=last=cur=NULL;}
     ~TSpisok();   // деструктор
     void Add(TElement *e); // добавление элемента в список
     TElement *Del(void);   // удаление элемента из списка
     void ForEach(void (*f)(TElement *e)); // поэлементная обработка 
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
void TSpisok::ForEach(void (*f)(TElement *e))
{ 
    cur=first;  
    while (cur!=NULL) { (*f)(cur); cur=cur->suc;}  
}
class TSortSpisok:public TSpisok // класс Cортированный список
{    
  protected:
     virtual int Compare(void *op1,void *op2)=0; /* абстрактный метод
                                                       сравнения для процедуры сортировки  */
  public:
     void Sort(void);        // метод сортировки
     TSortSpisok(void):TSpisok(){}      // конструктор
     ~TSortSpisok(){}       // деструктор
};
void TSortSpisok::Sort(void)
{
    int swap=1;      TElement *temp;
    while (swap)  
    {
        swap=0;  cur=first; 
        while (cur->suc!=NULL)
        {
            if (Compare(cur,cur->suc))
            { 
                temp=cur->suc; 
                cur->suc=temp->suc; 
                temp->suc=cur;
                if (cur->pre!=NULL)  
                     cur->pre->suc=temp;  
                else first=temp;
                temp->pre=cur->pre;   
                cur->pre=temp;
                if (cur->suc!=NULL)  
                     cur->suc->pre=cur;   
                else last=cur;
                cur=temp; swap=1;
            }
            else cur=cur->suc;  
        }            
    }
}
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
class TSSpisok:public TSortSpisok /*  класс Пользовательский                                                                                
                                                                       сортированный список*/
{
 protected:
    virtual int Compare(void *op1,void *op2) /* метод 
                 сравнения для процедуры сортировки с явным преобразованием типа */
    { return  (((TTabl *)op1)->num)<(((TTabl *)op2)->num);}
 public:
    TSSpisok(void):TSortSpisok(){}
    ~TSSpisok(void){}
};
void Show(TElement *e)  // процедура для передачи в метод ForEach 
{   e->Print(); }
TSSpisok N;         // объект класса Сортированный список
void main()
{ 
    setlocale(0,"russian");
    int k;    char str[40];    char str2[20];
    TElement *p; //  указатель на базовый класс Telement
    // цикл формирования списка из объектов классов TNum, TStr, TTabl
    while ( printf("Введите число:"),scanf("%d",&k)!=EOF)
    { 
        p=new TNum(k);   N.Add(p);
        printf("Введите строку:");  scanf("%s",str);
        printf("Введите строку 2:"); scanf("%s",str2);
        p=new TTabl(str,str2);      N.Add(p);
        printf("Введите строку:");  scanf("%s",str);
        p=new TStr(str);            N.Add(p);     
    }
    puts("\nВведены элементы:");
    N.ForEach(Show);   // вывод элементов списка
    N.Sort();          // сортировка
     puts("\nПосле сортировки:");
     N.ForEach(Show);       
	_getch();
}
