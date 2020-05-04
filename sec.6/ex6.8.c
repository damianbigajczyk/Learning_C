#include <stdio.h>

int main(int argc, char *argv[])
{
	float a = 0;
	float b = 0;

	puts("Enter two numbers, please:");
	while (scanf("%f %f", &a, &b) == 2) {
		printf("%f\n", (a - b)/(a*b));
		puts("Enter two numbers, please:");
	}
	puts("The end");

	return 0;
}
