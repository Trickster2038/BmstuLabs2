#include <iostream>
#include <string.h>
using namespace std;
class TA 
{
 protected:	char c;
 public:       TA(char ac):c(ac){}
	virtual void func(){cout<<c<<endl;}
};
class TB:public TA
{ 
    char S[10];
 public:     TB(char *aS):TA(aS[0]){strcpy(S,aS);}
    void func(){cout<<c<<' '<<S<<endl;}
}; 
void main()
{ 
   TA *pA=new TA('A'),*pC=new TB("AB");
   TB *pB=new TB("AC");
      // восходящее приведение типов 
   ((TA *)pB)->func();   
   reinterpret_cast<TA *>(pB)->func();
   static_cast<TA *>(pB)->func();
   dynamic_cast<TA *>(pB)->func();
      // нисходящее приведение типов - корректно 
   ((TB *)pC)->func();
   reinterpret_cast<TB *>(pC)->func(); 
   static_cast<TB *>(pC)->func(); 
   dynamic_cast<TB *>(pC)->func(); 
      // нисходящее приведение типов - некорректно 
   ((TB *)pA)->func(); 
   reinterpret_cast<TB *>(pA)->func(); 
   static_cast<TB *>(pA)->func(); 
   // dynamic_cast<TB *>(pA)->func();  // фиксирует ошибку!
       // проверка корректности нисходящего преобразования
   if (TB *pD=dynamic_cast<TB *>(pA)) pD->func();
   else cout<<"Cast Error"<<endl;
   system("pause");
} 
