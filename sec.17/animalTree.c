#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "animalTree.h"

typedef struct pair {
	Node *parent;
	Node *child;
} Pair;

static bool ToLeft(const Animal *ptrA1, const Animal *ptrA2);
static bool ToRight(const Animal *ptrA1, const Animal *ptrA2);
static Pair FindAnimal(const Animal *ptrA, const Tree *ptree);
static Node *CreateAnimal(const Animal *ptrA);
static void AddNode(Node *new, Node *root);
static bool AddSpecies(const Animal *ptrA, Node *root);
static void InSequence(Node *root, void (* pfun)(Animal animal));
static void DeleteAllNode(Node *ptrNode);
static void DeleteList(Node *ptrList);
static void DeleteNode(Node **ptr);

void InitTree(Tree *ptree)
{
	ptree->root = NULL;
	ptree->size = 0;
}
_Bool EmptyTree(const Tree *ptree)
{
	return (ptree->size == 0) ? true : false;
}
_Bool FullTree(const Tree *ptree)
{
	return (ptree->size == MAXPOS) ? true : false;
}
int CountAnimals(const Tree *ptree)
{
	return ptree->size;
}
_Bool AddAnimal(const Animal *ptrA, Tree *ptree)
{
	Node *newAnimal;
	Node *foundAnimal;
	if (FullTree(ptree)) {
		puts("Failed to add animal. Tree is full");
		return false;
	}
	if ((foundAnimal = FindAnimal(ptrA, ptree).child) != NULL) {
		AddSpecies(ptrA, foundAnimal);
		ptree->size++;
		return false;
	}
	newAnimal = CreateAnimal(ptrA);
	if (newAnimal == NULL) {
		fprintf(stderr, "Failed to create new node\n");
		return false;
	}
	ptree->size++;
	if (ptree->root == NULL)
		ptree->root = newAnimal;
	else
		AddNode(newAnimal, ptree->root);
	return true;
}
_Bool InTree(const Animal *ptrA, const Tree *ptree)
{
	Node *foundAnimal;
	Animal *current;
	if ((foundAnimal = FindAnimal(ptrA, ptree).child) == NULL)
		return false;
	current = &(foundAnimal->animal);
	while (current != NULL) {
		if (strcmp(ptrA->species, current->species) == 0) {
			int i = 1;
			current = &(foundAnimal->animal);
			printf("This is a list of \"%s\":\n", current->name);
			while (current != NULL) {
				printf("%d) Species: %-19s\n", i++, current->species);
				current = current->next;
			}
			return true;
		}
		current = current->next;
	}
	return false;
}
_Bool DeleteAnimal(const Animal *ptrA, Tree *ptree)
{
	Pair foundAnimal = FindAnimal(ptrA, ptree);
	if ((foundAnimal.child == NULL))
		return false;
	if (strcmp(ptrA->species, foundAnimal.child->animal.species) == 0 &&
		foundAnimal.child->animal.next == NULL) {

		if (foundAnimal.parent == NULL)
			DeleteNode(&ptree->root);
		else if (foundAnimal.parent->left == foundAnimal.child)
			DeleteNode(&foundAnimal.parent->right);
		else
			DeleteNode(&foundAnimal.parent->right);
		ptree->size--;
		return true;
	} else if (strcmp(ptrA->species, foundAnimal.child->animal.species) == 0 &&
			foundAnimal.child->animal.next != NULL) {

		Animal *nextAnimal = foundAnimal.child->animal.next;
		strcpy(foundAnimal.child->animal.name, nextAnimal->name);
		strcpy(foundAnimal.child->animal.species, nextAnimal->species);
		foundAnimal.child->animal.next = nextAnimal->next;
		free(nextAnimal);
		ptree->size--;
		return true;
	} else {
		Animal *previous = &(foundAnimal.child->animal);
		Animal *current = foundAnimal.child->animal.next;
		while (current != NULL) {
			if (strcmp(ptrA->species, current->species) == 0) {
				previous->next = current->next;
				free(current);
				ptree->size--;
				return true;
			} else {
				previous = current;
				current = current->next;
			}
		}
	}
	return false;
}
void ExecuteAll(const Tree *ptree, void (* pfun)(Animal animal))
{
	if (ptree != NULL)
		InSequence(ptree->root, pfun);
}
void DeleteTree(Tree *ptree)
{
	if (ptree != NULL)
		DeleteAllNode(ptree->root);
	ptree->root = NULL;
	ptree->size = 0;
}

/******************************************/
/*           static funnctions            */
/******************************************/

static bool ToLeft(const Animal *ptrA1, const Animal *ptrA2)
{
	return (strcmp(ptrA1->name, ptrA2->name) < 0) ? true : false;
}
static bool ToRight(const Animal *ptrA1, const Animal *ptrA2)
{
	return (strcmp(ptrA1->name, ptrA2->name) > 0) ? true : false;
}
static Pair FindAnimal(const Animal *ptrA, const Tree *ptree)
{
	Pair target;
	target.parent = NULL;
	target.child = ptree->root;

	while (target.child != NULL) {
		if (ToLeft(ptrA, &(target.child->animal))) {
			target.parent = target.child;
			target.child = target.child->left;
		} else if (ToRight(ptrA, &(target.child->animal))) {
			target.parent = target.child;
			target.child = target.child->right;
		} else
			break;
	}
	return target;
}
static Node *CreateAnimal(const Animal *ptrA)
{
	Node *new = (Node *) malloc(sizeof(Node));
	if (new != NULL) {
		new->animal = *ptrA;
		new->animal.next = NULL;
		new->left = NULL;
		new->right = NULL;
	}
	return new;
}
static void AddNode(Node *new, Node *root)
{
	if (ToLeft(&new->animal, &root->animal)) {
		if (root->left == NULL)
			root->left = new;
		else
			AddNode(new, root->left);
	} else if (ToRight(&new->animal, &root->animal)) {
		if (root->right == NULL)
			root->right = new;
		else
			AddNode(new, root->right);
	} else {
		fprintf(stderr, "Error function AddNode()\n");
		exit(EXIT_FAILURE);
	}
}
static bool AddSpecies(const Animal *ptrA, Node *root)
{
	Animal *previous = &root->animal;
	Animal *new = (Animal *) malloc(sizeof(Animal));
	if (new == NULL)
		return false;

	strcpy(new->name, ptrA->name);
	strcpy(new->species, ptrA->species);
	new->next = NULL;

	if (previous->next == NULL)
		previous->next = new;
	else {
		while (previous->next != NULL)
			previous = previous->next;
		previous->next = new;
	}
	return true;
}
static void InSequence(Node *root, void (* pfun)(Animal animal))
{
	if (root != NULL) {
		InSequence(root->left, pfun);
		(* pfun)(root->animal);
		InSequence(root->right, pfun);

	}
}
static void DeleteAllNode(Node *ptrNode)
{
	Node *pright;
	if (ptrNode != NULL) {
		pright = ptrNode->right;
		DeleteAllNode(ptrNode->left);
		DeleteList(ptrNode);
		free(ptrNode);
		DeleteAllNode(pright);
	}
}
static void DeleteList(Node *ptrList)
{
	Animal *current = ptrList->animal.next;
	Animal *temp;
	while (current != NULL) {
		temp = current;
		current = current->next;
		free(temp);
	}
	ptrList->animal.next = NULL;
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
