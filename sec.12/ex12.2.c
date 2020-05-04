#include <stdio.h>
#include "pe12_2a.h"

int main(int argc, char *argv[])
{
	int mode;

	fputs("Choose: 0 - metric system, 1 - US system: ", stdout);
	while (scanf("%d", &mode) != 1) {
		puts("Wrong input, try again!");
		while (getchar() != '\n') {} 
	}
	while (mode >= 0) {
		setMode(mode);
		getData();
		showData();
		fputs("Choose: 0 - metric system, 1 - US system.\n", stdout);
		fputs("(-1 to end): ", stdout);
		scanf("%d", &mode);
	}
	puts("The end");
	return 0;
}
