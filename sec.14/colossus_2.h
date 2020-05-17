#ifndef colossus_2_H_
#define colossus_2_H_

#define ID 6
#define NAME 15
#define SEATS 12


struct seat {
	char id[ID];
	_Bool clear;
	_Bool confirmed;
	char name[NAME];
	char surname[NAME];
};

typedef void (*V_SEAT)(struct seat*);

char *readIn(char *s, int MAX);

int menu(void);
int initMenu(void);
void nFreeSeat(struct seat *);
void listFreeSeat(struct seat *);
void alphaFreeSeat(struct seat *);
void bookSeat(struct seat *);
void delBook(struct seat *);
void confirm(struct seat *);
#endif
