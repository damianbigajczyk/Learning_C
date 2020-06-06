#ifndef queue_H_
#define queue_H_
#include <stdbool.h>

typedef int Position;
#define MAXQUEUE 10
typedef struct node {
	Position position;
	struct node *next;
} Node;

typedef struct queue {
	Node *head;
	Node *tail;
	int amount;
} Queue;

void InitQueue(Queue *pq);
bool FullQueue(const Queue *pq);
bool EmptyQueue(const Queue *pq);
int CountAmount(const Queue *pq);
bool Set(Position position, Queue *pq);
bool Detach(Position *p_position, Queue *pq);
void ClearQueue(Queue *pq);

#endif
