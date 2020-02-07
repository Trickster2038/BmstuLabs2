#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <excpt.h>
#include <iostream>
using namespace std;
#define MY_EXCEPTION 0x0000FACE
void func()
{
   RaiseException(MY_EXCEPTION,0,0,0);
}
DWORD ExceptionFilter(DWORD dwCode)
{
   if (dwCode==MY_EXCEPTION)
         return EXCEPTION_EXECUTE_HANDLER;
   else  return EXCEPTION_CONTINUE_SEARCH;   
}
void somefunc()
{
   __try { func(); }
   __except(ExceptionFilter(GetExceptionCode()))
   {
	   cout<<"MyException"<<endl;
   } 
} 
void main()
{
	   somefunc();
	   system("pause");
} 
