#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main()
{
	puts("Enter string");
	int cnt = 0, i = 0;;
	char s[50], * k;
	gets_s(s);
	while (s[i] != '\0') {
		if (s[i] == '#') {
			cnt++;
		}
		i++;
	}
	printf("found #: %d \n", cnt);

	if (cnt <= 1) {
		puts("less then two # symbs");
	}
	else
	{
		i = 0;
		while (s[i] != '#') {
			i++;
		}
		i++;
		while (s[i] != '#') {
			k = &s[i];
			printf("\n %X", k);
			i++;
		}
	}
	_getch();
	return 0;
}