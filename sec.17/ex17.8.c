#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "animalTree.h"

int menu(_Bool begin);
void addAnimal(Tree *ptr);
void deleteAnimal(Tree *ptr);
void showAnimal(Tree *ptr);
void findAnimal(Tree *ptr);
void amount(Tree *ptr);
void showSpecies(Animal animal);
void largeLetter(char *s);
char *readIn(char *to, int n);

typedef void (*V_FUN)(Tree *ptr);
V_FUN pf[] = {addAnimal, showAnimal, amount, findAnimal, deleteAnimal};

int main(int argc, char **argv)
{
	Tree animal;
	int index;
	InitTree(&animal);
	index = menu(1);
	while (index >= 0 && index <= 4) {
		pf[index](&animal);
		index = menu(0);
	}
	DeleteTree(&animal);
	puts("See you!");

	return 0;
}

int menu(_Bool begin)
{
	int ch;
	if (begin) {
		puts("************ The Animal's Club - records of members ***********");
		puts("1) Add animal\t\t\t2) Display list of animals");
		puts("3) Amount of animals\t\t4) Find animal");
		puts("5) Delete animal\t\t6) Exit");
	}
	fputs("\nWhat do you want to do: ", stdout);
	while ((ch = getchar()) != EOF) {
		while (getchar() != '\n') {}
		if (strchr("123456", ch) == NULL)
			puts("Enter 1,2,3,4,5 or 6 to exit");
		else
			return ch - 49;
	}
}
void addAnimal(Tree *ptr)
{
	Animal temp;
	if (FullTree(ptr))
		puts("No free record");
	else {
		fputs("Enter the name of animal: ", stdout);
		readIn(temp.name, LEN);
		fputs("Enter the species of animal: ", stdout);
		readIn(temp.species, LEN);
		largeLetter(temp.name);
		largeLetter(temp.species);
		AddAnimal(&temp, ptr);
	}
}
void deleteAnimal(Tree *ptr)
{
	Animal toDelete;
	if (EmptyTree(ptr)) {
		puts("No position");
		return;
	}
	fputs("Enter the name of animal to delete: ", stdout);
	readIn(toDelete.name, LEN);
	fputs("Enter the species of animal: ", stdout);
	readIn(toDelete.species, LEN);
	largeLetter(toDelete.name);
	largeLetter(toDelete.species);
	printf("%s, %s ", toDelete.name, toDelete.species);
	if (DeleteAnimal(&toDelete, ptr))
		puts("has been deleted");
	else
		puts("isn't a member of club");
}
void showAnimal(Tree *ptr)
{
	 if (EmptyTree(ptr))
		 puts("Nothing to display");
	 else
		 ExecuteAll(ptr, showSpecies);
}
void findAnimal(Tree *ptr)
{
	Animal temp;
	if (EmptyTree(ptr)) {
		puts("No records");
		return;
	}
	fputs("Enter the name of animal to find: ", stdout);
	readIn(temp.name, LEN);
	fputs("Enter the species of animal: ", stdout);
	readIn(temp.species, LEN);
	largeLetter(temp.name);
	largeLetter(temp.species);
	if (InTree(&temp, ptr))
		printf("%s, %s is a member of club\n", temp.name, temp.species);
	else
		printf("%s, %s isn't a member of club\n", temp.name, temp.species);
}
void amount(Tree *ptr)
{
	printf("%d animals in club.\n", CountAnimals(ptr));
}
void showSpecies(Animal animal)
{
	Animal *current = &animal;
	while (current != NULL) {
		printf("Animal: %-19s  Species: %-19s\n", current->name, current->species);
		current = current->next;
	}
}
void largeLetter(char *s)
{
	while (*s != '\0') {
		*s = toupper(*s);
		s++;
	}
}
char *readIn(char *to, int n)
{
	char *result;
	char *here;
	result = fgets(to, n, stdin);
	if (result) {
		here = strchr(to, '\n');
		if (here)
			*here = '\0';
		else
			while (getchar() != '\n') {}
	}
	return result;
}
