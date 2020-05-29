#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM 10

struct person {
	char name[20];
	char surname[20];
};

void showArray(struct person *tab);
int compare(const void *w1, const void *w2);

int main(int argc, char** argv)
{
	struct person personel[NUM] = {
		{"James", "Lancaster"},
		{"Harper", "Goody"},
		{"Avery", "Dalton"},
		{"Jackson", "Keene"},
		{"Madison", "Camden"},
		{"Ella", "Manley"},
		{"Avery", "Oakes"},
		{"Carter", "Paxton"},
		{"Wyatt", "Hamilton"},
		{"Jack", "Nibley"}
	};

	showArray(personel);
	qsort(personel, NUM, sizeof(struct person), compare);
	puts("\nResult:\n");
	showArray(personel);

	return 0;
}

void showArray(struct person *tab)
{
	for (int i = 0; i < NUM; i++)
		printf("%d) %-20s %-20s\n", i+1, (tab+i)->name, (tab+i)->surname);
}

int compare(const void *w1, const void *w2)
{
	const struct person *a1 = (const struct person *) w1;
	const struct person *a2 = (const struct person *) w2;

	return strcmp(a1->surname, a2->surname);
}
