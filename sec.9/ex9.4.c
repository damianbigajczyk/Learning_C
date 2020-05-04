#include <stdio.h>

double harmonicMean(double a, double b)
{
	return 2 / ((1/a) + (1/b));
}

int main(int argc, char**argv)
{
	printf("The harmonic mean of 2 and 5 is %.2lf\n", harmonicMean(2, 5));

	return 0;
}
