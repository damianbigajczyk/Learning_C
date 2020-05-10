#include <stdio.h>
#include "function.h"

int main(int argc, char *argv[])
{
	char array[10][50];
	int choice = 0;
	int count = loadString(array);

	if (!count) {
		puts("Nothing to read");
		return 0;
	}
	menu();
	while (1) {
		while (scanf("%d", &choice) != 1) {
			puts("Wrong input, try again!");
			while (getchar() != '\n') {}
		}
		switch (choice) {
			case 1:
				showString(array, count, 1);
				break;
			case 2:
				showString(array, count, 2);
				break;
			case 3:
				showString(array, count, 3);
				break;
			case 4:
				showString(array, count, 4);
				break;
			case 5:
				return 0;
			default:
				puts("Choose number from 1 to 5");
				while (getchar() != '\n') {}
				continue;
		}
		menu();
	}

	return 0;
}
