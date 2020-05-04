#include <stdio.h>

int contained(const char *s, int c)
{
	while (*s != '\0') {
		if (*s == c) {
			return 1;
		} else {
			s++;
		}
	}
	return 0;
}

int main(int argc, char *argv[])
{
	char array[] = "Daman  	 adsf  	";

	if (contained(array, 'i')) {
		puts("YES");
	} else {
		puts("NO");
	}

	return 0;
}
