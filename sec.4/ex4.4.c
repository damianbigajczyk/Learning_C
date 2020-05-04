#include <stdio.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
	uint8_t height = 0;
	char name[10];

	printf("Hi!, what is your name?\n");
	scanf("%s", name);

	printf("How tall are you? (Enter your hight in centimeters)\n");
	scanf("%hhu", &height);

	printf("%s, you have %1.2f meters tall.\n", name, (float) height/100);

	return 0;
}
