#include <stdio.h>
#include <float.h>

int main(int argc, char *argv[])
{
	double a = 1.0 / 3.0;
	float b = 1.0 / 3.0;

	printf("a(double) - %d\t\t\tb(float) - %d\n", DBL_DIG, FLT_DIG);
	printf("%.4lf\t\t\t\t%.4f\n", a, b);
	printf("%.12lf\t\t\t%.12f\n", a, b);
	printf("%.16lf\t\t%.16f\n", a, b);

	return 0;
}
