#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list_2.h"

static void CpyToRecord(Movie object, Movie *record);

void InitList(List *plist)
{
	plist->amount = 0;
}

bool EmptyList(const List *plist)
{
	return (plist->amount == 0) ? true : false;
}

bool FullList(const List *plist)
{
	return (plist->amount == MAXSIZE) ? true : false;
}
unsigned int CountItems(const List *plist)
{
	return (unsigned int) (plist->amount);
}
bool AddMovie(Movie object, List *plist)
{
	if (plist->amount == MAXSIZE)
		return false;
	CpyToRecord(object, &plist->record[plist->amount]);
	plist->amount++;
	return true;
}
void Pass(const List *plist, void (*pfun)(Movie object))
{
	for (int i = 0; i < plist->amount; i++)
		(*pfun)(plist->record[i]);
}
void ClearList(List *plist)
{
	for (int i = 0; i < MAXSIZE; i++) {
		memset(plist->record[i].title, '\0', TITLE);
		plist->record[i].rating = 0;
	}
	plist->amount = 0;
}

static void CpyToRecord(Movie object, Movie *record)
{
	strcpy(record->title, object.title);
	record->rating = object.rating;
}
