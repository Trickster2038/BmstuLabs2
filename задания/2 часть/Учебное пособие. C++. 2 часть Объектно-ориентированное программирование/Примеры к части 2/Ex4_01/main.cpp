#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
class TGroup
{
    class TStudent
    {
     private: char * Famyli,*Name;   float old;
     public: 
        char * getFam() {   return Famyli;  }
        char * getName(){   return Name;  }
        float getold()  {   return old;  }
        void setstudent()
        { 
           char s[30];
           puts("input famyli");  gets(s);
           Famyli= new char [strlen(s)+1]; 
           strcpy(Famyli,s);
           puts("input Name");  gets(s);
           Name= new char [strlen(s)+1];
           strcpy(Name,s);
           puts("Input Old");   gets(s);
           old=atof(s);
        }
        void printst()
        {
            printf("%15s %10s %6.2f\n",
               getFam(), getName(), getold());
        }
    };
    int size;   TStudent *Masgroup;
 public:
    void TGroup::setgroup(int asize)
    {
       size=asize; Masgroup=new TStudent[size];
       for(int i=0;i<size;i++)
           Masgroup[i].setstudent();
    }
    void printGr()
    {
        puts("Information of Group");
        for(int i=0;i<size;i++)
            Masgroup[i].printst();
    }
};
void main()
{
    TGroup AK;   int n;
    puts("input n<=30"); 
	scanf("%d\n",&n);
    AK.setgroup(n);
    AK.printGr();
    _getch();
}
