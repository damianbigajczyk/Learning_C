#include <stdio.h>
#include <string.h>
#include <stdint.h>

char *copyString(char *s1, const char *s2, int n);

int main(int argc, char* argv[])
{
	/**
	 * Segmentation fault gdy char *s1 = "Damian"
	 * wskznika nie mozna zmieniac tylko tablice
	 * section 11 page 470
	 **/
	char s1[] = "Damian";
	char s2[] = "Bigajczyk";

	puts(copyString(s2,s1,10));
	return 0;
}

char *copyString(char *s1, const char *s2, int n)
{
	uint8_t s1Length = strlen(s1);
	uint8_t s2Length = strlen(s2);
	int i = 0;

	if (s1Length == s2Length) {
		for(i = 0; i < n && i < s1Length; i++) {
			s1[i] = s2[i];
		}
		return s1;
	} else if ( s1Length > s2Length ) {
		for(i = 0; i < n && i < s2Length; i++) {
			s1[i] = s2[i];
		}
		for( ; i < n && i < s1Length; i++) {
			s1[i] = '\0';
		}
		return s1;
	} else {	
		for(i = 0; i < n && i < s1Length; i++) {
			*(s1 + i) = *(s2 +i);
		}
		*(s1 + i) = '\0';
		return s1;
	}
	return NULL;
}
