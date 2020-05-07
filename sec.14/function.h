#ifndef function_H_
#define function__

struct months {
	char name[10];
	char abb[5];
	__uint8_t days;
	char number[3];
};

int getDays(const char *s);
__uint8_t getDay(void);
char *getMonth(char *to);
__uint16_t getYear(void);
__uint16_t countDays(__uint8_t day, char *month, __uint16_t year);

#endif
