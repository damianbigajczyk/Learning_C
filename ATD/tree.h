#ifndef tree_H_
#define tree_H_

typedef struct position {
	char name[20];
	char species[20];
} Position;

#define MAXPOS 10

typedef struct node {
	Position position;
	struct node *left;
	struct node *right;
} Node;

typedef struct tree {
	Node *root;
	int size;
} Tree;

void InitTree(Tree *ptree);
_Bool EmptyTree(const Tree *ptree);
_Bool FullTree(const Tree *pptree);
int CountPositions(const Tree *ptree);
_Bool AddPosition(const Position *pp, Tree *ptree);
_Bool InTree(const Position *pp, const Tree *ptree);
_Bool DeletePosition(const Position *pp, Tree *ptree);
void Pass(const Tree *ptree, void (* pfun)(Position position));
void DeleteTree(Tree *ptree);

#endif
