#ifndef ObjectH
#define ObjectH
class A
{    
  public:    
     void func(char ch);   
};
class B : private A 
{    
  public: 
     void func(char *str);
     using A::func;        // ����������� B::func
};
#endif
