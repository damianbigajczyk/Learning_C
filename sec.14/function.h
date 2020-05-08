#ifndef function_H_
#define function__

#define MAXTYT 40
#define MAXAUT 40
#define MAXKS 100

struct book {
	char title[MAXTYT];
	char author[MAXAUT];
	float price;
};

struct months {
	char name[10];
	char abb[5];
	__uint8_t days;
	char number[3];
};

/* Exercise 14.1 and 14.2 */
int getDays(const char *s);
char *getMonth(char *to);
__uint8_t getDay(void);
__uint16_t getYear(void);
__uint16_t countDays(__uint8_t day, char *month, __uint16_t year);
/*****************************************************************/

char *readIn(char *to, int n);
void sortTitle(struct book *, int n);
#endif
