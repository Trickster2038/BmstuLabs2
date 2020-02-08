#include <stdio.h>
#include <conio.h>
#include <math.h>

int main() {
	puts("Enter x,z,r");
	int x, z, r;
	scanf("%d %d %d", &x, &z, &r);
	float p, q;
	p = sin(x - 5.1 * z);
	q = log(x / r);
	p = q / p;
	printf("result: %3.2f", p);
	return 0;
}