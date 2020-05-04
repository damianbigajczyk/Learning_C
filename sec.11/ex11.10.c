#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdint.h>

char *deleteSpace(char *s)
{
	uint8_t count = 0;
	bool copy = false;
	char *temp = s;

	while (*s != '\0') {
		if (isspace(*s)) {
			count++;
			copy = true;
			while (isspace(*(++s))) {
				count++;
			}
		} else {
			if (copy)
				*(s-count) = *s;
			s++;
			continue;
		}
		*(s-count) = *s;
		s++;

	}
	while (count)
		*(s-(count--)) = '\0';

	return temp;
}



int main(int argc, char *argv[])
{
	char s[] = "Ula ma     kota";

	puts(deleteSpace(s));	

	return 0;
}
