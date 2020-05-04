#include <stdio.h>

#define mila 1.609
#define galon 3.785

int main(int argc, char *argv[])
{
	float miles = 0;
	float galons = 0;

	printf("Hello! How many miles have you driven?\n");
	scanf("%f", &miles);

	printf("How many galons have you consumed?\n");
	scanf("%f", &galons);

	printf("You have been consuming %0.1f [mils/galon], which is equal to %.1f [l/100km].\n",
			(miles / galons), (galons * galon * 100) / (miles * mila));

	return 0;
}
