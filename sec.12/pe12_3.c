#include <stdio.h>
#include "pe12_3.h"

int setMode(void)
{
	int mode = 0;

	fputs("Choose: 0 - metric system, 1 - US system.\n", stdout);
	fputs("(-1 to end): ", stdout);
	while (scanf("%d", &mode) != 1) {
		puts("Wrong input, try again!");
		while (getchar() != '\n') {}
	}

	return mode;
}

void getData(const int mode, float *distance, float *usage)
{
	switch (mode) {
		case 0:
			fputs("Enter the traveled way in kilometers: ", stdout);
			while (scanf("%f", distance) != 1) {
				puts("Wrong input, try again!");
				while (getchar() != '\n') {}
			}
			fputs("Enter the consumed fuel in liters: ", stdout);
			while (scanf("%f", usage) != 1) {
				puts("Wrong input, try again!");
				while (getchar() != '\n') {}
			}
			break;
		case 1:
			fputs("Enter the traveled way in miles: ", stdout);
			while (scanf("%f", distance) != 1) {
				puts("Wrong input, try again!");
				while (getchar() != '\n') {}
			}
			fputs("Enter the consumed fuel in galons: ", stdout);
			while (scanf("%f", usage) != 1) {
				puts("Wrong input, try again!");
				while (getchar() != '\n') {}
			}
			break;
		default:
			puts("I shoudln't be here");
	}
}

void showData(const int mode, const float *distance, const float *usage)
{
	switch (mode) {
		case 0:
			printf("Fuel consumption amounted to %.2f liters per 100 km\n", 100 * (*usage) / (*distance));
			break;
		case 1:
			printf("Fuel consumption amounted to %.2f mils per galon\n", (*distance) / (*usage));
			break;
		default:
			puts("I shoudln't be here");
	}
}


