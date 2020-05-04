#include <stdio.h>

int main(int argc, char *argv[])
{
	char ch = '\0';
	int i = 0;

	while ((ch = getchar()) != EOF) {
		i++;
		switch (ch) {
			case ' ':
				printf("%d) SPACE - %d\t", i, ch);
				break;
			case '\t':
				printf("%d) \\t - %d\t", i, ch);
				break;
			case '\n':
				printf("%d) \\n - %d\t", i, ch);
				break;
			default:
				printf("%d) %c - %d\t", i, ch, ch);
		}

		if (!(i % 10))
			putchar('\n');
		
	}
	putchar('\n');

	return 0;
}
		   			       
