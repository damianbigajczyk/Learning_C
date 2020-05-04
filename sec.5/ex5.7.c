#include <stdio.h>

float thirdPower(float a)
{
	return a*a*a;
}

int main(int argc, char *argv[])
{
	float number = 0;

	puts("Enter a number, please:");
	while (scanf("%f", &number) != 1) {
		puts("Wrong input, try again!");
		while (getchar() != '\n')
			continue;
	}
	
	printf("%f to third power is equal %f\n", number, thirdPower(number));

	return 0;
}
