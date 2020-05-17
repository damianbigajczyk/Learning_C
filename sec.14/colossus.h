#ifndef colossus_H_
#define colossus_H_

#define ID 6
#define NAME 15
#define SEATS 12


struct seat {
	char id[ID];
	_Bool clear;
	char name[NAME];
	char surname[NAME];
};

typedef void (*V_SEAT)(struct seat*);

char *readIn(char *s, int MAX);
int menu(_Bool);
void nFreeSeat(struct seat *);
void listFreeSeat(struct seat *);
void alphaFreeSeat(struct seat *);
void bookSeat(struct seat *);
void delBook(struct seat *);

#endif
