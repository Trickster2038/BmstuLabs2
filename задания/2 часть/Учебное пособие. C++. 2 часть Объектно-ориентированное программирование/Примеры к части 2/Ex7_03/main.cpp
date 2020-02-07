#include <stdio.h>
#include <windows.h>

void main()
{
	puts("hello");
	__try
	{
		puts("in try");
		__try
		{
			puts("in try");
			RaiseException(0,0,0,0); // генерация исключения
		}
		__finally
		{
			puts("in finally");
		}
	}
	__except( puts("in filter"), EXCEPTION_EXECUTE_HANDLER )
     {
		puts("in except");
	}
	puts("world");
	system("pause");
}
