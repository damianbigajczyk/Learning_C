#include <stdio.h>

int sumSquare(int a, int b)
{
	int sum = 0;
	while (a <= b) {
		sum += a * a;
		a++;
	}
	return sum;
}

int main(int argc, char *argv[])
{
	int a = 0;
	int b = 0;

	puts("Enter two numbers, please:");
	
	while ((scanf("%d %d", &a, &b) == 2) && (a < b)) {
		printf("Total squares from %d to %d is equal to %d.\n",
				a, b, sumSquare(a, b));

		puts("Enter two numbers, please:");
	}
	puts("The end");

	return 0;
}
