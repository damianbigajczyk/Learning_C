#include <stdio.h>

int main(int argc, char *argv[])
{
	float sum1 = 0;
	float sum2 = 0;
	int ammount = 0;

	fputs("How many \"words\" do you want to sum up: ", stdout);

	while ((scanf("%d", &ammount) == 1) && ammount >=0) {
		for(int i = 1; i <= ammount; i++) {
			sum1 += ( 1 / ((float)(i+1)) );
			sum2 += (i%2 == 0) ? 1/(float)(i+1) : -1/(float)(i+1);
		}
		printf("Sum1 = %.12f\nSum2 = %.12f\n", sum1, sum2);
		sum1 = 0;
		sum2 = 0;

		fputs("How many \"words\" do you want to sum up: ", stdout);
	}

	puts("The end");

	return 0;
}
