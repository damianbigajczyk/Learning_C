#include <stdio.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
	char array[26];
	uint8_t sign = 0;
	int i = 0;

	for(i = 0, sign = 97; i < 26; i++, sign++)
		*(array + i) = sign;

	for(i = 0; i < 26; i++)
		printf("%d - %c\n", i + 1, *(array + i));

	return 0;
}
