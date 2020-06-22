#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "wordsTree.h"

static void InOrder(const Node *root, void (*pfun)(Word word));
static void DeleteAllNode(Node *ptr);
static Node *CreateNode(const Word *pw);
static void AddNode(Node *new, Node *root);
static bool ToLeft(const Word *w1, const Word *w2);
static bool ToRight(const Word *w1, const Word *w2);

void InitTree(Tree *ptree)
{
	ptree->root = NULL;
	ptree->size = 0;	
}
_Bool EmptyTree(const Tree *ptree)
{
	return (ptree->root == NULL) ? true : false;
}
_Bool FullTree(const Tree *ptree)
{
	return (ptree->size == MAXPOS) ? true : false;
}
unsigned int SizeTree(const Tree *ptree)
{
	return ptree->size;
}
_Bool AddWord(const Word *pw, Tree *ptree)
{
	Node *new;
	Node *temp;
	if (FullTree(ptree)) {
		fprintf(stderr, "The tree is full\n");
		return false;
	}
	if ((temp = FindWord(pw, ptree)) != NULL) {
		temp->word.amount++;
		return false;
	}
	new = CreateNode(pw);
	if (new == NULL) {
		fprintf(stderr, "Failed to create new node\n");
		return false;
	}
	ptree->size++;
	if (ptree->root == NULL)
		ptree->root = new;
	else
		AddNode(new, ptree->root);
	return true;
}
Node *FindWord(const Word *pw, const Tree *ptree)
{
	Node *temp = ptree->root;
	while (temp != NULL) {
		if (strcmp(pw->s, temp->word.s) == 0)
			return temp;
		else if (ToLeft(pw, &temp->word))
			temp = temp->left;
		else
			temp = temp->right;
	}
	return temp;
}
void Execute(const Tree *ptree, void (*pfun)(Word word))
{
	if (ptree != NULL)
		InOrder(ptree->root, pfun);
}
void DeleteTree(Tree *ptree)
{
	if (ptree != NULL)
		DeleteAllNode(ptree->root);
	ptree->root = NULL;
	ptree->size = 0;
}
static void InOrder(const Node *root, void (*pfun)(Word word))
{
	if (root != NULL) {
		InOrder(root->left, pfun);
		(*pfun)(root->word);
		InOrder(root->right, pfun);
	}
}
static void DeleteAllNode(Node *ptr)
{
	Node *pright;
	if (ptr != NULL) {
		pright = ptr->right;
		DeleteAllNode(ptr->left);
		free(ptr);
		DeleteAllNode(pright);
	}
}
static Node *CreateNode(const Word *pw)
{
	Node *new;
	new = (Node *) malloc(sizeof(Node));
	if (new != NULL) {
		new->word = *pw;
		new->word.amount = 1;
		new->left = NULL;
		new->right = NULL;
	}
	return new;
}
static void AddNode(Node *new, Node *root)
{
	if (ToLeft(&new->word, &root->word)) {
		if (root->left == NULL)
			root->left = new;
		else
			AddNode(new, root->left);
	} else if (ToRight(&new->word, &root->word)) {
		if (root->right == NULL)
			root->right = new;
		else
			AddNode(new, root->right);
	} else {
		fprintf(stderr, "Error: function AddNode() failed\n");
		exit(1);
	}
}
static bool ToLeft(const Word *w1, const Word *w2)
{
	int temp;
	return ((temp = strcmp(w1->s, w2->s)) < 0) ? true : false;
}
static bool ToRight(const Word *w1, const Word *w2)
{
	int temp;
	return ((temp = strcmp(w1->s, w2->s)) > 0) ? true : false;
}


