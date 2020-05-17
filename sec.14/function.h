#ifndef function_H_
#define function__

#define MAXTYT 40
#define MAXAUT 40
#define MAXKS 100
#define NAME 20
#define SNAME 20
#define GRADE 5
#define SIZE 4

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

/*********** Exercise 14.4 *****************/
struct data {
	char firstName[NAME];
	char secondName[NAME];
	char surname[SNAME];
};

struct customer {
	int pesel[11];
	struct data id;
};

/********** Exercise 14.5 ******************/
struct daneos {
	char name[NAME];
	char surname[SNAME];
};

struct student {
	struct daneos person;
	float result[GRADE];
	float avgGrade;
};

/************* Exercise 14.1, 14.2 and 14.3 *************/
int getDays(const char *s);
char *getMonth(char *to);
__uint8_t getDay(void);
__uint16_t getYear(void);
__uint16_t countDays(__uint8_t day, char *month, __uint16_t year);
/*****************************************************************/

char *readIn(char *to, int n);
void sortTitle(struct book *, int n);


void displayPerson(const struct customer *Person);
void displayPerson_2(const struct customer Person[]);

void getGrade(struct student *data);
void displayStudent(const struct student *data);
void countAvg(struct student *data);
void displayAvgAll(const struct student *data);

char getFirst(void);

#endif
