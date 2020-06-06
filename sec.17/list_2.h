#ifndef list_2_H_
#define list_2_H_
#include <stdbool.h>
#define TITLE 45
#define MAXSIZE 100

struct movie {
	char title[TITLE];
	int rating;
};

typedef struct movie Movie;
typedef struct list {
	Movie record[MAXSIZE];
	int amount;
} List;

void InitList(List *plist);
bool EmptyList(const List *plist);
bool FullList(const List *plist);
unsigned int CountItems(const List *plist);
bool AddMovie(Movie item, List *plist);
void Pass(const List *plist, void (*pfun)(Movie item));
void ClearList(List *plist);

#endif
