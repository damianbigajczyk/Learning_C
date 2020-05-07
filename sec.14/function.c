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
