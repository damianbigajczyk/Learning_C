#include <stdio.h>
#include <stdlib.h>
#include "colossus.h"


int main(int argc, char **argv)
{
	V_SEAT wf[] = {nFreeSeat, listFreeSeat, alphaFreeSeat, bookSeat, delBook}; 
	struct seat person[SEATS] = {
		{"12a01", 0, "-", "-"},
		{"12a02", 0, "-", "-"},
		{"12a03", 0, "-", "-"},
		{"12a04", 0, "-", "-"},
		{"12a05", 0, "-", "-"},
		{"12a06", 0, "-", "-"},
		{"12a07", 0, "-", "-"},
		{"12a08", 0, "-", "-"},
		{"12a09", 0, "-", "-"},
		{"12a010", 0, "-", "-"},
		{"12a011", 0, "-", "-"},
		{"12a012", 0, "-", "-"}
	};

	int index;
	int counter = 0;
	size_t sizePerson = sizeof(struct seat);
	FILE *pf = NULL;

	if (!(pf = fopen("Plane.dot", "r+b"))) {
		if (!(pf = fopen("Plane.dot", "w+b"))) {
			fputs("Failed to open file: \"Plane.dot\"\n", stderr);
			exit(EXIT_FAILURE);
		}
		for (int i = 0; i < SEATS; i++)
			fwrite(&person[i], sizePerson, 1, pf);
		rewind(pf);
	}

	while (counter < SEATS && (fread(&person[counter], sizePerson, 1, pf) == 1)) {
	      if(!counter)
		      printf("\t%-6s\t%4s\t%-15s\t%-15s\n", "ID", "Free", "Name", "Surname");
	      printf("\t%-6s\t%2d\t%-15s\t%-15s\n", person[counter].id, person[counter].clear,
			      person[counter].name, person[counter].surname);
	      counter++;
	}
	rewind(pf);

	index = menu(1);
	while (index >= 0 && index <= 4) {
		wf[index](person);
		index = menu(0);
	}

	for (int i = 0; i < SEATS; i++)
		fwrite(&person[i], sizePerson, 1, pf);
	if (fclose(pf))
		puts("Failed to close file \"Plane.dot\"");

	return 0;
}
