#include <stdio.h>

int main(int argc, char *argv[])
{
	int i = 0;
	int j = 0;

	for(i = 0; i < 5; i++) {
		for(j = -1; j < i; j++) {
			putchar('$');
		}
		putchar('\n');
	}

	return 0;
}
