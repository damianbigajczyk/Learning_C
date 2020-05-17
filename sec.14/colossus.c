#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "colossus.h"

char *readIn(char *s, int MAX)
{
	char *result = NULL;
	char *here = NULL;

	result = fgets(s, MAX, stdin);
	if (result) {
		here = strchr(result, '\n');
		if (here)
			*here = '\0';
		else
			while (getchar() != '\n')
				continue;
	}

	return result;
}

int menu(bool a)
{
	char answer;

	puts("To choose option, press the letter:");
	puts("a) display amount of free seats");
	puts("b) display a list of free seats");
	puts("c) display a list of seat in alphabetic order");
	puts("d) booking a seat");
	puts("e) delete a reservation");
	if (a)
		puts("f) The end");
	answer = tolower(getchar());
	while (getchar() != '\n') {}
	while (!strchr("abcdef", answer)) {
		puts("Enter a, b, c, d, e or f");
		answer = tolower(getchar());
		while (getchar() != '\n') {}
	}
	return (int)(answer - 97);
}
void nFreeSeat(struct seat *person)
{
	uint8_t counter = 0;

	for (int i = 0; i < SEATS; i++)
		if (!((person + i)->clear))
			counter++;
	if (counter == 1) {
	       puts("There is one seat left");
	} else if (counter > 1) {
		printf("There are %hhu seats left\n", counter);
	} else {
		puts("There is no seat left");	
	}
}
void listFreeSeat(struct seat *person)
{
	uint8_t counter = 0;
	
	printf("\t%-6s\t%4s\t%-15s\t%-15s\n", "ID", "Free", "Name", "Surname");
	for (int i = 0; i < SEATS; i++)
		if (!((person + i)->clear)) {
	      		printf("\t%-6s\t%2d\t%-15s\t%-15s\n", person[i].id, person[i].clear,
			     		 person[i].name, person[i].surname);
			counter++;
		}
	if (!counter)
		puts("There is no seat left");
}
void alphaFreeSeat(struct seat *person)
{
	uint8_t id[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
	uint8_t temp;	
	int i;
	int n = SEATS - 1;
	bool swap = true;

	while (swap) {
		swap = false;
		for (i = 0; i < n; i++) {
			if (strcmp(person[*(id + i)].surname, person[*(id +i + 1)].surname) > 0) {
				temp = id[i];
				id[i] = id[i+1];
				id[i+1] = temp;
				swap = true;
			}
		}
		n--;
	}	

	printf("\t%-6s\t%4s\t%-15s\t%-15s\n", "ID", "Free", "Name", "Surname");
	for (i = 0; i < SEATS; i++)
		printf("\t%-6s\t%2d\t%-15s\t%-15s\n", person[*(id + i)].id, person[*(id + i)].clear,
				person[*(id + i)].name, person[*(id + i)].surname);
}
void bookSeat(struct seat *person)
{
	char temp[NAME];
	int i;

	for (i = 0; i < SEATS; i++)
		if (!person[i].clear) {
			puts("To stop press [ENTER]");
			fputs("Enter your name, please: ", stdout);
			if (!readIn(temp, NAME) || temp[0] == '\0')
				break;
			strcpy(person[i].name, temp);
			memset(temp, '\0', NAME);
			fputs("Enter your surname, please: ", stdout);
			if (!readIn(temp, NAME) || temp[0] == '\0')
				break;
			strcpy(person[i].surname, temp);
			person[i].clear = 1;
			break;
		}
	if (i == SEATS+1)
		puts("There no seat left");
}
void delBook(struct seat *person)
{
	char temp[ID];
	bool flag = true;

	puts("Please enter the ID of your seat to delete or [enter] to stop");
	readIn(temp, ID);
	while (temp[0] != '\0') {
		for (int i = 0; i < SEATS; i++) {
			if (!strcmp((person + i)->id, temp)) {
				memset(person[i].name, '\0', NAME);
				person[i].name[0] = '-';
				memset(person[i].surname, '\0', NAME);
				person[i].surname[0] = '-';
				person[i].clear = 0;
				flag = false;
				break;
			}
		}
		if (!flag)
			break;
		printf("There is no such ID: %s, try again:\n", temp);
		readIn(temp, ID);
	}
}
