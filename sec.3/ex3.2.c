#include <stdio.h>

int main(int argc, char *argv[])
{
	int sign = 65;

	while (sign) {
		printf("Enter a sign in ASCII code, please (0 - the end\n");
		while (scanf("%d", &sign) != 1) {
			printf("Wrong input, try again!\n");
			while (getchar() != '\n') {} //clear buffer
		}
		printf("%c\n", sign);
	}

	return 0;
}
