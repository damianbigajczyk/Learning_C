#include <stdio.h>
#include <ctype.h>

int getFirst(void)
{
	int ch = getchar();

	while (!isprint(ch))
		ch = getchar();

	while (getchar() != '\n') {}

	return ch;
}

int main(int argc, char *argv[])
{
	char ch;
	
	while ((ch = getFirst()) != '#') {
		putchar(ch);
		putchar('\n');
	}
		
	return 0;
}
