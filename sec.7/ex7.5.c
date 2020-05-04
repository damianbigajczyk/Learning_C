#include <stdio.h>

int main(int argc, char *argv[])
{
	char ch = '\0';

	while ((ch = getchar()) != '#') {
		switch(ch) {
			case '.':
				putchar('!');
				break;
			case '!':
				fputs("!!", stdout);
				break;
			default:
				putchar(ch);
		}
	}
	puts("The end");

	return 0;
}
