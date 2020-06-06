#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

static void CpyToNode(Movie object, Node *node);

void InitList(List *plist)
{
	*plist = NULL;
}

bool EmptyList(const List *plist)
{
	return (*plist == NULL) ? true : false;
}

bool FullList(const List *plist)
{
	Node *wsk;
	bool full;
	wsk = (Node *) malloc(sizeof(Node));
	if (wsk == NULL)
		full = true;
	else
		full = false;
	free(wsk);
	return full;
}
unsigned int CountItems(const List *plist)
{
	unsigned int counter = 0;
	Node *p = *plist;
	while (p != NULL) {
		counter++;
		p = p->next;
	}
	return counter;
}
bool AddMovie(Movie object, List *plist)
{
	Node *pnew;
	Node *tail = *plist;
	pnew = (Node *) malloc(sizeof(Node));
	if (pnew == NULL)
		return false;
	CpyToNode(object, pnew);
	pnew->next = NULL;
	if (tail == NULL)
		*plist = pnew;
	else {
		while (tail->next != NULL)
			tail = tail->next;
		tail->next = pnew;
	}
	return true;
}
void Pass(const List *plist, void (*pfun)(Movie object))
{
	Node *p = *plist;
	while (p != NULL) {
		(*pfun)(p->object);
		p = p->next;
	}
}
void ClearList(List *plist)
{
	Node *p;
	while (*plist != NULL) {
		p = (*plist)->next;
		free(*plist);
		*plist = p;
	}
}

static void CpyToNode(Movie object, Node *pnode)
{
	pnode->object = object;
}
