#include <stdio.h>
#include <stdint.h>

#define foot 30.48
#define cal 2.54

int main(int argc, char *argv[])
{
	float height = 0;

	puts("How tall are you in centimeters?");
	while (scanf("%f", &height) != 1) {
		puts("Wrong input, try again!");
		while (getchar() != '\n')
			continue;
	}
	
	while (height > 0) {
		printf("%.2f cm = %.2f ft, %.2f cal\n", height, height/foot, height/cal);

		puts("How tall are you in centimeters? (0 - the end)");
		while (scanf("%f", &height) != 1) {
			puts("Wrong input, try again!");
			while (getchar() != '\n')
				continue;
		}
	}

	puts("Good bey!");

	return 0;
}
