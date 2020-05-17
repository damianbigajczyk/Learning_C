#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "colossus_2.h"

struct seat P102[SEATS] = {
	{"12a01", 0, 0, "-", "-"},
	{"12a02", 0, 0, "-", "-"},
	{"12a03", 0, 0, "-", "-"},
	{"12a04", 0, 0, "-", "-"},
	{"12a05", 0, 0, "-", "-"},
	{"12a06", 0, 0, "-", "-"},
	{"12a07", 0, 0, "-", "-"},
	{"12a08", 0, 0, "-", "-"},
	{"12a09", 0, 0, "-", "-"},
	{"12a10", 0, 0, "-", "-"},
	{"12a11", 0, 0, "-", "-"},
	{"12a12", 0, 0, "-", "-"}
};
struct seat P311[SEATS] = {
	{"12b01", 0, 0, "-", "-"},
	{"12b02", 0, 0, "-", "-"},
	{"12b03", 0, 0, "-", "-"},
	{"12b04", 0, 0, "-", "-"},
	{"12b05", 0, 0, "-", "-"},
	{"12b06", 0, 0, "-", "-"},
	{"12b07", 0, 0, "-", "-"},
	{"12b08", 0, 0, "-", "-"},
	{"12b09", 0, 0, "-", "-"},
	{"12b10", 0, 0, "-", "-"},
	{"12b11", 0, 0, "-", "-"},
	{"12b12", 0, 0, "-", "-"}
};
struct seat P444[SEATS] = {
	{"12c01", 0, 0, "-", "-"},
	{"12c02", 0, 0, "-", "-"},
	{"12c03", 0, 0, "-", "-"},
	{"12c04", 0, 0, "-", "-"},
	{"12c05", 0, 0, "-", "-"},
	{"12c06", 0, 0, "-", "-"},
	{"12c07", 0, 0, "-", "-"},
	{"12c08", 0, 0, "-", "-"},
	{"12c09", 0, 0, "-", "-"},
	{"12c10", 0, 0, "-", "-"},
	{"12c11", 0, 0, "-", "-"},
	{"12c12", 0, 0, "-", "-"}
};
struct seat P519[SEATS] = {
	{"12d01", 0, 0, "-", "-"},
	{"12d02", 0, 0, "-", "-"},
	{"12d03", 0, 0, "-", "-"},
	{"12d04", 0, 0, "-", "-"},
	{"12d05", 0, 0, "-", "-"},
	{"12d06", 0, 0, "-", "-"},
	{"12d07", 0, 0, "-", "-"},
	{"12d08", 0, 0, "-", "-"},
	{"12d09", 0, 0, "-", "-"},
	{"12d10", 0, 0, "-", "-"},
	{"12d11", 0, 0, "-", "-"},
	{"12d12", 0, 0, "-", "-"}
};

int initMenu(void)
{
	char ch;
	puts("Welcome to Colossus airport line\nChoose your line");
	puts("1) 102\n2) 311\n3) 444\n4) 519\n5) The end");
	ch = getchar();
	while (getchar() != '\n') {}
	while (!strchr("12345", ch)) {
		puts("Enter 1,2,3,4 or 5");
		ch = getchar();
		while (getchar() != '\n'){}
	}
	return (int) (ch - 49);
}
int menu(void)
{
	char answer;

	puts("To choose option, press the letter:");
	puts("a) display amount of free seats");
	puts("b) display a list of free seats");
	puts("c) display a list of seat in alphabetic order");
	puts("d) booking a seat");
	puts("e) delete a reservation");
	puts("f) confirm a reservation");
	puts("g) Back to line");
	answer = tolower(getchar());
	while (getchar() != '\n') {}
	while (!strchr("abcdefg", answer)) {
		puts("Enter a, b, c, d, e or f");
		answer = tolower(getchar());
		while (getchar() != '\n') {}
	}
	return (int)(answer - 97);
}
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

	printf("\t%-6s\t%4s\t%s\t%-15s\t%-15s\n", "ID", "Free", "Confirm", "Name", "Surname");
	for (int i = 0; i < SEATS; i++)
		if (!((person + i)->clear)) {
	      		printf("\t%-6s\t%2d\t%3d\t%-15s\t%-15s\n", person[i].id, person[i].clear,
			     		 person[i].confirmed, person[i].name, person[i].surname);
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

	printf("\t%-6s\t%4s\t%s\t%-15s\t%-15s\n", "ID", "Free", "Confirm", "Name", "Surname");
	for (i = 0; i < SEATS; i++)
		printf("\t%-6s\t%2d\t%3d\t%-15s\t%-15s\n", person[*(id + i)].id, person[*(id + i)].clear,
				person[*(id + i)].confirmed, person[*(id + i)].name, person[*(id + i)].surname);
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
void confirm(struct seat *person)
{
	char temp[ID];
	bool flag = true;

	puts("Please enter the ID of your seat to confirm a reservation or [enter] to stop");
	readIn(temp, ID);
	while (temp[0] != '\0') {
		for (int i = 0; i < SEATS; i++) {
			if (!strcmp((person + i)->id, temp)) {
				person[i].confirmed = 1;
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
				person[i].confirmed = 0;
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
