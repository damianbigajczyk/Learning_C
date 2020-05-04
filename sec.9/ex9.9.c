#include <stdio.h>

double power(double x, int y)
{
	if (x == 0)
		return 0;
	if (y == 0)
		return 1;
	if (y == 1)
		return x;
	if (y < 0) {
		y *= (-1);
		return 1/(x * power(x, --y));
	}
	return x * power(x, --y);
}

int main(int argc, char *argv[])
{
	double x = 0;
	int y = 1;

	scanf("%lf %d %*s", &x, &y);
	printf("Result: %lf\n", power(x, y));

	return 0;
}
