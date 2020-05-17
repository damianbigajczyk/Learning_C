#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "function.h"

int main(int argc, char **argv)
{
	struct book lib[MAXKS];
	int counter = 0;
	int index, counterp;
	FILE *pbook = NULL;
	int size = sizeof(struct book);

	if (!(pbook = fopen("book.dat", "r+b"))) {
		fputs("Failed to open file: \"book.dat\"\n", stderr);
		exit(EXIT_FAILURE);
	}

	rewind(pbook);

	while (counter < MAXKS && fread(&lib[counter], size, 1, pbook) == 1) {
		if (!counter)
			puts("The file contains:");
		printf("%d) %s by %s: %.2f$\n", counter + 1, lib[counter].title,
				lib[counter].author, lib[counter].price);
		counter++;
	}
	counterp = counter;
	fclose(pbook);

	if (counter == MAXKS) {
		fputs("The file is full.\n", stderr);
		exit(2);
	}
	puts("Pass new title of a book or press [enter] to end");
	while (counter < MAXKS && readIn(lib[counter].title, MAXTYT) != NULL
			&& lib[counter].title[0] != '\0') {
		puts("Now enter the author:");
		readIn(lib[counter].author, MAXAUT);
		puts("How much is the book cost?");
		while (scanf("%f", &lib[counter].price) != 1) {
			puts("Wrong input, try again");
			while (getchar() != '\n') {}
		}
		while (getchar() != '\n')
			continue;
		if (++counter < MAXKS)
			puts("Pass the next tile of a book or [enter] to end:");
	}
	if (counter > 0) {
		puts("The is your list of books.\nIf you want to remove a record enter 'd'\n\
				If you want to change a record, enter 'c', or press [Enter] to contineu.");
		bool *precord = calloc(counter-1, sizeof(bool));
		for (index = 0; index < counter; index++) {
			printf("%d) %s, author: %s, price: %.2f$\n", index + 1, lib[index].title,
					lib[index].author, lib[index].price);
			switch (getFirst()) {
				case 'd':
					precord[index] = true;
					break;
				case 'c':
					puts("Pass new title of the book:");
					readIn(lib[index].title, MAXTYT);
					puts("Now enter the author:");
					readIn(lib[index].author, MAXAUT);
					puts("How much is the book cost?");
					while (scanf("%f", &lib[index].price) != 1) {
						puts("Wrong input, try again");
						while (getchar() != '\n') {}
					}
					while (getchar() != '\n')
						continue;
					break;
				default:
					break;
			}
		}

		pbook = fopen("book.dat", "w + b");

		for (index = 0; index < counter; index++) {
			if (precord[index])
				continue;
			printf("%s, author: %s, price: %.2f$\n", lib[index].title,
					lib[index].author, lib[index].price);
			fwrite(&lib[index], size, 1, pbook);
		}
		fclose(pbook);
		free(precord);
	} else
		puts("No books? It's a pity");
	puts("The end");

	return 0;
}

