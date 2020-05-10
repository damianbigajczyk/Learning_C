#include <stdio.h>
#include <string.h>

#define sentence "Dawno potem i nastepnie"

char *findSign(char *s, int c);

int main(int argc, char *argv[])
{
	char array[] = "Damian";

	puts(findSign(array, 'i'));
	puts(findSign(sentence, 'i'));
	return 0;
}

char *findSign(char *s, int c)
{
	while (*s != '\0') {
		if (*s == c) {
			return s;
		} else {
			s++;
		}
	}
	return NULL;	
}
