#include <stdio.h>

int isAlpha(char ch)
{
	if (ch >= 'A' && ch <= 'Z') {
		return ch - 64; 
	} else if (ch >= 'a' && ch <= 'z') {
		return ch - 96;
	} else 
		return -1;
}

int main(int argc, char *argv[])
{
	char ch = '\0';

	while ((ch = getchar()) != EOF) {
		int rc = isAlpha(ch);
		(rc != -1) ? printf("%c is a letter with alphabetic number: %d\n", ch, rc) :
			printf("%c is not a letter\n", ch == '\n' ? ' ' : ch);
	}

	return 0;
}
