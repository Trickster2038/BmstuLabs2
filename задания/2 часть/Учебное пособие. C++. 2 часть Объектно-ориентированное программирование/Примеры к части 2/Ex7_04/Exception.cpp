#include <string.h>
#include "Exception.h"
MyException::MyException(char* s = "Unknown")
{ what = strdup(s);  }
MyException::MyException(const MyException& e )
{ what = strdup(e.what); }
MyException::~MyException() 
{ delete[] what; }
char* MyException::msg() const
{ return what; }
