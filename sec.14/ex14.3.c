#include <stdio.h>
#include <string.h>
#include "function.h"

int main(int argc, char *argv[])
{
	struct book library[MAXKS];
	float sum = 0;
	int counter = 0;

	puts("Pass the title of a book or press [enter] to end");
	while (counter < MAXKS
			&& readIn(library[counter].title, MAXTYT) != NULL
			&& library[counter].title[0] != '\0') {
		puts("Now, enter the author");
		readIn(library[counter].author, MAXAUT);
		puts("How much is the book cost?");
		while (scanf("%f", &library[counter].price) != 1) {
			puts("Wrong input, try again");
			while (getchar() != '\n') {}
		}
		while (getchar() != '\n')
			continue;
		if (++counter < MAXKS)
			puts("Pass the next tile of a book or [enter] to end:");
	}

	if (counter) {
		sortTitle(library, counter);
		puts("This is your list of books:");
		for (int index = 0; index < counter; index++) {
			printf("%s, author: %s, price: %.2f$\n", library[index].title,
					library[index].author, library[index].price);
			sum += library[index].price;
		}
	} else
		puts("No books? It's a pity");
	if (sum)
		printf("Total price: %.2f$\n", sum);

	return 0;
}

