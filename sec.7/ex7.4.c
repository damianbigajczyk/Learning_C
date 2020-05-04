#include <stdio.h>

int main(int argc, char *argv[])
{
	char ch = '\0';

	while ((ch = getchar()) != '#') {
		if(ch == '.') {
			putchar('!');
		} else if(ch == '!') {
			fputs("!!", stdout);
		} else
			putchar(ch);
	}
	puts("The end");

	return 0;
}
