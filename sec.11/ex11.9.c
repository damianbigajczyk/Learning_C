#include <stdio.h>
#include <string.h>
#include <stdint.h>

char *reverse(char *s)
{
	uint8_t point = strlen(s);
	char temp = '\0';

	for(int i = 0; i < (strlen(s)/2) ; i++) {
		temp = *(s + i);
		*(s + i) = *(s + (--point));
		*(s + point) = temp;
	}
	return s;
}


int main(int argc, char *argv[])
{
	char name[] = "Damiann";

	puts(reverse(name));

	return 0;
}
