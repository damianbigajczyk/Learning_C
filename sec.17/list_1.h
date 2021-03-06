#ifndef list_1_H_
#define list_1_H_
#include <stdbool.h>
#define TITLE 45

struct movie {
	char title[TITLE];
	int rating;
};

typedef struct movie Movie;
typedef struct node {
	Movie object;
	struct node *next;
} Node;

typedef struct list {
	Node *head;
	Node *tail;
} List;

void InitList(List *plist);
bool EmptyList(const List *plist);
bool FullList(const List *plist);
unsigned int CountItems(const List *plist);
bool AddMovie(Movie item, List *plist);
void Pass(const List *plist, void (*pfun)(Movie item));
void ClearList(List *plist);

#endif
