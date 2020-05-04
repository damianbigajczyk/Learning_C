#include <stdio.h>
#include "pe12_2a.h"

static int mode = 1;
static float distance = 0;
static float usage = 0;

void setMode(int newMode)
{
	mode = (newMode == 0 || newMode == 1) ? newMode : mode;
}

void getData(void)
{
	switch(mode) {
		case 0:
			fputs("Enter the traveled way in kilometers: ", stdout);
			scanf("%f", &distance);
			fputs("Enter the consumed fuel in liters: ", stdout);
			scanf("%f", &usage);
			break;
		case 1:
			fputs("Enter the traveled way in miles: ", stdout);
			scanf("%f", &distance);
			fputs("Enter the consumed fuel in galons: ", stdout);
			scanf("%f", &usage);
			break;
		default:
			puts("I shoudln't be here");
	}
}

void showData(void)
{
	switch(mode) {
		case 0:
			printf("Fuel consumption amounted to %.2f liters per 100 km\n", 100 * usage / distance);
			break;
		case 1:
			printf("Fuel consumption amounted to %.2f mils per galon\n", distance / usage);
			break;
		default:
			puts("I shoudln't be here");
	}
}


