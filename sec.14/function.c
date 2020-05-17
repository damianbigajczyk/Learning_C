#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "function.h"

const static struct months mon[] = {
	{"January", "Jan.", 31, '1'},
	{"February", "Feb.", 28, '2'},
	{"March", "Mar.", 31, '3'},
	{"April", "Apr.", 30, '4'},
	{"May", "May", 31, '5'},
	{"June", "Jun.", 30, '6'},
	{"July", "Jul", 31, '7'},
	{"August", "Aug.", 31, '8'},
	{"September", "Sep.", 30, '9'},
	{"October", "Oct.", 31, "10"},
	{"November", "Nov.", 30, "11"},
	{"December", "Dec.", 31, "12"}
};

int getDays(const char *s)
{
	int i = 0;
	int sum = 0;
	bool matched = false;

	for (i = 0; i < 12; i++)
		if (!strcmp(mon[i].name, s)) {
			matched = true;
			break;
		}
	if (!matched)
		return -1;

	for ( ; i >= 0; i--)
		sum += mon[i].days;

	return sum;
}
uint8_t getDay(void)
{
	uint8_t day = 0;

	puts("Which day is it?");
	while (scanf("%hhu", &day) != 1) {
		puts("Wrong input, try again!");
		while (getchar() != '\n'); {}
	}
	while (getchar() != '\n') {}

	return day;
}
char *getMonth(char *to)
{
	char *result = NULL;
	char *here = NULL;
	int i = 0;
	int n = 0;

	fputs("Which month is it?\n", stdout);
	result = fgets(to, 10, stdin);

	if (result) {
		here = strchr(to, '\n');
		if (here)
			*here = '\0';
		else
			while (getchar() != '\n') {}
	} else
		return result;
	
	if (strlen(to) < 3 )
		return result;
	else {
		*(to) = toupper(*to);
		while (*(to + ++i) != '\0')
			*(to + i) = tolower(*(to + i));
	}

	return result;	
}

uint16_t getYear(void)
{
	uint8_t year = 0;

	puts("Which year is it?");
	while (scanf("%hhu", &year) != 1) {
		puts("Wrong input, try again!");
		while (getchar() != '\n'); {}
	}
	return year;
}

uint16_t countDays(uint8_t day, char *month, uint16_t year)
{
	bool matched = false;
	uint16_t days = day;
	int i = 0;

	for (i = 0; i < 12; i++)
		if (!strcmp(mon[i].name, month) || !strcmp(mon[i].abb, month)
				|| !strcmp(mon[i].number, month)) {
			matched = true;
			break;
		}

	if (!matched) {
		printf("%s isn't a month\n", month);
		return 0;
	}

	days += ((i > 1) && !(year % 4))? 1 : 0;

	for (--i; i >=0; i--)
		days += mon[i].days;

	return days;
}

char *readIn(char *to, int n)
{
	char *result = NULL;
	char *here = NULL;

	result = fgets(to, n, stdin);
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

void sortTitle(struct book *lib, int n)
{
	struct book temp;
	bool swap;
	int i;
	int rc = 0;
	int times = n;

	do {
		for (i = 0, --times, swap = false; i < times; i++) {
			if ((rc = strcmp(lib[i].title, lib[i+1].title)) > 0) {
				temp = lib[i];
				lib[i] = lib[i+1];
				lib[i+1] = temp;
				swap = true;
			}
		}
	} while (swap);
}
/******************* Exercise 14.4 ***************************/
void displayPerson(const struct customer *Person)
{
	for (int i = 0; i < 3; i++) {
		printf("%s, %s", Person->id.surname, Person->id.firstName);
		(Person->id.secondName[0] != '\0') ? printf(" %c. -- ", Person->id.secondName[0]) :
			printf(" -- ");
		for (int j = 0; j < 11; j++)
			printf("%d", Person->pesel[j]);
		putchar('\n');
		Person++;
	}
}
void displayPerson_2(const struct customer Person[])
{
	for (int i = 0; i < 3; i++) {
		printf("%s, %s", Person[i].id.surname, Person[i].id.firstName);
		(Person[i].id.secondName[0] != '\0') ? printf(" %c. -- ", Person[i].id.secondName[0]) :
			printf(" -- ");
		for (int j = 0; j < 11; j++)
			printf("%d", Person[i].pesel[j]);
		putchar('\n');
	}
}

/******************** Exercise 14.5 ***************************/
void getGrade(struct student *data)
{
	int i, j;

	for (i = 0; i < SIZE; i++, data++) {
		printf("The results of %s %s\nEnter grades, please:\n", data->person.name, data->person.surname);
		for (j = 0; j < GRADE; j++) {
			printf("%d - ", j+1);
			while (scanf("%f", &data->result[j]) != 1) {
				puts("Wrong input, try again!");
				while (getchar() != '\n') {}
			}
		}
	}
}
void displayStudent(const struct student *data)
{
	int i, j;

	for (i = 0; i < SIZE; i++, data++) {
		printf("\t\t%s %s\nGrades:\t\t", data->person.name, data->person.surname);
		for (j = 0; j < GRADE; j++)
			printf("%.2f\t", data->result[j]);
		printf("\nAverage grade: %2.f\n", data->avgGrade);
	}
}
void countAvg(struct student *data)
{
	int i, j;
	float sum = 0;

	for (i = 0; i < SIZE; i++, data++) {
		for (j = 0, sum = 0; j < GRADE; j++)
			sum += data->result[j];
		data->avgGrade = sum/GRADE;
	}
}
void displayAvgAll(const struct student *data)
{
	int i;
	float sum = 0;

	for (i = 0; i < SIZE; i++, data++)
		sum += data->avgGrade;
	printf("Average all of students: %.2f\n", sum/SIZE);
}

/********************* Exercise 14.7 ****************************/
char getFirst(void)
{
	char ch = getchar();
	if (ch == '\n')
		return ch;
	while(getchar() != '\n') {}
	if (isalpha(ch))
		return tolower(ch);
	return '\n';
}
