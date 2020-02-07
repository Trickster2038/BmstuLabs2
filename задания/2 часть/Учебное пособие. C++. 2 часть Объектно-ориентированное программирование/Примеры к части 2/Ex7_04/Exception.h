#ifndef ExceptionH
#define ExceptionH
class MyException     // класс Мое исключение
{ 
  private:  char* what;       // поле сообщения
  public:  
     MyException(char* s);
     MyException(const MyException& e);
     ~MyException();
     char* msg()const; 
};
#endif