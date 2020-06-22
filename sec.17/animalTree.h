#ifndef animalTree_H_
#define animalTree_H_

#define LEN 15
#define MAXPOS 100

typedef struct animal {
	char name[LEN];
	char species[LEN];
	struct animal *next;
} Animal;
typedef struct node {
	Animal animal;
	struct node *left;
	struct node *right;
} Node;
typedef struct tree {
	Node *root;
	int size;
} Tree;

void InitTree(Tree *ptree);
_Bool EmptyTree(const Tree *ptree);
_Bool FullTree(const Tree *ptree);
int CountAnimals(const Tree *ptree);
_Bool AddAnimal(const Animal *ptrA, Tree *ptree);
_Bool InTree(const Animal *ptrA, const Tree *ptree);
_Bool DeleteAnimal(const Animal *ptrA, Tree *ptree);
void ExecuteAll(const Tree *ptree, void (* pfun)(Animal animal));
void DeleteTree(Tree *ptree);

#endif

