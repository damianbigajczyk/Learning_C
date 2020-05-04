#include <stdio.h>

int main(int argc, char* argv[])
{
	char ch = '\0';
	int a = 0;
	int b = 0;
	int c = 0;

	printf("Hello\n");
	while ((ch = getchar()) != '#')
	{
		switch(ch) {
			case ' ':
				a++;
				break;
			case '\n':
				b++;
				break;
			default:
				c++;
				break;
		}
	}
	printf("space: %d, new line: %d, others: %d\n", a, b, c);

	return 0;
}
