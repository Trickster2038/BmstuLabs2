#ifndef ExceptionH
#define ExceptionH
class MyException     // ����� ��� ����������
{ 
  private:  char* what;       // ���� ���������
  public:  
     MyException(char* s);
     MyException(const MyException& e);
     ~MyException();
     char* msg()const; 
};
#endif