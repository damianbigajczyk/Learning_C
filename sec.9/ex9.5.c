#include <stdio.h>

void larger_than(double *a, double *b)
{
	if(*a > *b) {
		*b = *a;
	} else {
		*a = *b;
	}
}

int main(int argc, char *argv[])
{
	double a = 2.999991;
	double b = 2.999992;

	printf("a = %.7lf\tb = %.7lf\t\n", a, b);

	larger_than(&a, &b);
	
	printf("a = %.7lf\tb = %.7lf\t\n", a, b);

	return 0;
}
