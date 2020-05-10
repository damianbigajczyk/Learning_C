#include <stdio.h>

#define m 3.0e-23	//mass od one water molecule
#define l 1000		//liter of water in grams

int main(int argc, char *argv[])
{
	float volume = 0;

	printf("Enter volume of water in liters, please (0 - the end):\n");
	while (scanf("%f", &volume) != 1) {
		puts("Wrong input, try again!");
		while (getchar() != '\n') {}
	}

	while (volume) {
		printf("You have %1.5e water molecules.\n", volume * l / m);
		printf("Enter volume of water, please (0 - the end):\n");
		while (scanf("%f", &volume) != 1) {
			puts("Wrong input, try again!");
			while (getchar() != '\n') {}
		}
	}

	return 0;
}

