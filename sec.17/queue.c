#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

static void CpyToNode(Position position, Node *pn);
static void CpyToPosition(Node *pn, Position *pp);

void InitQueue(Queue *pq)
{
	pq->head = pq->tail = NULL;
	pq->amount = 0;
}
bool FullQueue(const Queue *pq)
{
	return pq->amount == MAXQUEUE;
}
bool EmptyQueue(const Queue *pq)
{
	return pq->amount == 0;
}
int CountAmount(const Queue *pq)
{
	return pq->amount;
}
bool Set(Position position, Queue *pq)
{
	Node *pnew;
	if (FullQueue(pq))
		return false;
	pnew = (Node *) malloc(sizeof(Node));
	if (pnew == NULL) {
		fprintf(stderr, "Error memory allocation!\n");
		exit(1);
	}
	CpyToNode(position, pnew);
	pnew->next = NULL;
	if (EmptyQueue(pq))
		pq->head = pnew;
	else
		pq->tail->next = pnew;
	pq->tail = pnew;
	pq->amount++;
	return true;
}
bool Detach(Position *p_position, Queue *pq)
{
	Node *pn;
	if (EmptyQueue(pq))
		return false;
	CpyToPosition(pq->head, p_position);
	pn = pq->head;
	pq->head = pq->head->next;
	free(pn);
	pq->amount--;
	if (pq->amount == 0)
		pq->tail = NULL;
	return true;
}
void ClearQueue(Queue *pq)
{
	Position detach;
	while (!EmptyQueue(pq))
		Detach(&detach, pq);
}

static void CpyToNode(Position position, Node *pn)
{
	pn->position = position;
}
static void CpyToPosition(Node *pn, Position *pp)
{
	*pp = pn->position;
}
