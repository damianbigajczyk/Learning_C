#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tree.h"

typedef struct pair {
	Node *parent;
	Node *child;
} Pair;

static Node *CreateNode(const Position *pp);
static bool ToLeft(const Position *p1, const Position *p2);
static bool ToRight(const Position *p1, const Position *p2);
static void AddNode(Node *new, Node *root);
static void InOrder(const Node *root, void (*pfun)(Position position));
static Pair FindPosition(const Position *pp, const Tree *ptree);
static void DeleteNode(Node **ptr);
static void DeleteAllNode(Node *ptr);

void InitTree(Tree *ptree)
{
	ptree->root = NULL;
	ptree->size = 0;
}
_Bool EmptyTree(const Tree *ptree)
{
	if (ptree->root == NULL)
		return true;
	else
		return false;
}
_Bool FullTree(const Tree *ptree)
{
	if (ptree->size == MAXPOS)
		return true;
	else
		return false;
}
int CountPositions(const Tree *ptree)
{
	return ptree->size;
}
_Bool AddPosition(const Position *pp, Tree *ptree)
{
	Node *new;
	if (FullTree(ptree)) {
		fprintf(stderr, "Tree is full\n");
		return false;
	}
	if (FindPosition(pp, ptree).child != NULL) {
		fprintf(stderr, "The position already exist\n");
		return false;
	}
	new = CreateNode(pp);
	if (new == NULL) {
		fprintf(stderr, "Can't create new node\n");
		return false;
	}
	ptree->size++;
	if (ptree->root == NULL)
		ptree->root = new;
	else
		AddNode(new, ptree->root);
	return true;
}
_Bool InTree(const Position *pp, const Tree *ptree) {
	return (FindPosition(pp, ptree).child ==NULL) ? false : true;
}
_Bool DeletePosition(const Position *pp, Tree *ptree) {
	Pair find;
	find = FindPosition(pp, ptree);
	if (find.child == NULL)
		return false;
	if (find.parent == NULL)
		DeleteNode(&ptree->root);
	else if (find.parent->left == find.child)
		DeleteNode(&find.parent->left);
	else
		DeleteNode(&find.parent->right);
	ptree->size--;
	return true;
}
void Pass(const Tree *ptree, void (* pfun)(Position position)) {
	if (ptree != NULL)
		InOrder(ptree->root, pfun);
}
void DeleteTree(Tree *ptree) {
	if (ptree != NULL)
		DeleteAllNode(ptree->root);
	ptree->root = NULL;
	ptree->size = 0;
}

static Node *CreateNode(const Position *pp) {
	Node *new;
	new = (Node *) malloc(sizeof(Node));
	if (new != NULL) {
		new->position = *pp;
		new->left = NULL;
		new->right = NULL;
	}
	return new;
}
static bool ToLeft(const Position *p1, const Position *p2) {
	int compare;
	if ((compare = strcmp(p1->name, p2->name)) < 0)
		return true;
	else if (compare == 0 && strcmp(p1->species, p2->species) < 0)
		return true;
	else
		return false;
}
static bool ToRight(const Position *p1, const Position *p2) {
	int compare;
	if ((compare = strcmp(p1->name, p2->name)) > 0)
		return true;
	else if (compare == 0 && strcmp(p1->species, p2->species) > 0)
		return true;
	else
		return false;
}
static void AddNode(Node *new, Node *root) {
	if (ToLeft(&new->position, &root->position)) {
		if (root->left == NULL)
			root->left = new;
		else
			AddNode(new, root->left);
	} else if (ToRight(&new->position, &root->position)) {
		if (root->right == NULL)
			root->right = new;
		else
			AddNode(new, root->right);
	} else {
		fprintf(stderr, "Error function AddNode()\n");
		exit(EXIT_FAILURE);
	}
}
static void InOrder(const Node *root, void (*pfun)(Position position)) {
	if (root != NULL) {
		InOrder(root->left, pfun);
		(*pfun)(root->position);
		InOrder(root->right, pfun);
	}
}
static Pair FindPosition(const Position *pp, const Tree *ptree) {
	Pair find;
	find.parent = NULL;
	find.child = ptree->root;
	if (find.child == NULL)
		return find;
	while (find.child != NULL) {
		if (ToLeft(pp, &(find.child->position))) {
			find.parent = find.child;
			find.child = find.child->left;
		} else if (ToRight(pp, &(find.child->position))) {
			find.parent = find.child;
			find.child = find.child->right;
		} else
			break;
	}
	return find;
}
static void DeleteNode(Node **ptr) {
	Node *temp;
	if ((*ptr)->left == NULL) {
		temp = *ptr;
		*ptr = (*ptr)->right;
		free(temp);
	} else if ((*ptr)->right == NULL) {
		temp = *ptr;
		*ptr = (*ptr)->left;
		free(temp);
	} else {
		for (temp = (*ptr)->left; temp->right != NULL; temp = temp->right)
			continue;
		temp->right = (*ptr)->right;
		temp = *ptr;
		*ptr = (*ptr)->left;
		free(temp);
	}
}
static void DeleteAllNode(Node *ptr) {
	Node *pright;
	if (ptr != NULL) {
		pright = ptr->right;
		DeleteAllNode(ptr->left);
		free(ptr);
		DeleteAllNode(pright);
	}
}
