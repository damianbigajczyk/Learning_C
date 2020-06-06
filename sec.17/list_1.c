#include <stdio.h>
#include <stdlib.h>
#include "list_1.h"

static void CpyToNode(Movie object, Node *node);

void InitList(List *plist)
{
	plist->head = NULL;
	plist->tail = NULL;
}

bool EmptyList(const List *plist)
{
	return (plist->head == NULL) ? true : false;
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
	Node *current = plist->head;
	while (current != NULL) {
		counter++;
		current = current->next;
	}
	return counter;
}
bool AddMovie(Movie object, List *plist)
{
	Node *pnew;
	Node *previous = plist->tail;
	pnew = (Node *) malloc(sizeof(Node));
	if (pnew == NULL)
		return false;
	CpyToNode(object, pnew);
	pnew->next = NULL;
	if (plist->head == NULL) {
		plist->head = plist->tail = pnew;
	} else if (plist->head == plist->tail) {
		plist->tail = pnew;
		plist->head->next = plist->tail;
	}
	else {
		plist->tail = pnew;
		previous->next = plist->tail;
	}
	return true;
}
void Pass(const List *plist, void (*pfun)(Movie object))
{
	Node *p = plist->head;
	while (p != NULL) {
		(*pfun)(p->object);
		p = p->next;
	}
}
void ClearList(List *plist)
{
	Node *p;
	while (plist->head != NULL) {
		p = plist->head->next;
		free(plist->head);
		plist->head = p;
	}
}

static void CpyToNode(Movie object, Node *pnode)
{
	pnode->object = object;
}
