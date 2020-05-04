#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char *containString(char *s1, char *s2)
{
	int i = 0;
	bool matched = false;

	while (*s1 != '\0') {
		if (*s2 == *s1) {
			matched = true;
			for(i = 1; *(s2 + i) != '\0'; i++) {
				if (s2[i] == s1[i]) {
					continue;
				} else {
					matched = false;
					break;
				}
			}
			if (matched)
				return s1;
		}
		s1++;		
	}

	return NULL;
}

int main(int argc, char* argv[])
{
	char s1[] = "Puuuuuuula";
	char s2[] = "ul";
	char *wsk = NULL;

	wsk = containString(s1, s2);
	if (wsk)
		puts(wsk);
	return 0;
}
