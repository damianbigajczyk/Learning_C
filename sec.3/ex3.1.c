#include <stdio.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
	uint8_t x1 = 150;

	printf("The range of x1 is from 0 to 255.\n");
	printf("x1 = 150?\t%u\n", x1);
	printf("x1 = 255?\t%u\n", x1 = 255);
	printf("x1 = 256?\t%u\n", x1 = 256);
	printf("x1 = 257?\t%u\n", x1 = 257);
	printf("x1 = 258?\t%u\n", x1 = 258);
	printf("x1 = 0?\t\t%u\n", x1 = 0);
	printf("x1 = -1?\t%u\n", x1 = -1);
	printf("x1 = -2?\t%u\n", x1 = -2);
	printf("x1 = -3?\t%u\n", x1 = -3);
	return 0;
}
