#ifndef wordsTree_H_
#define wordsTree_H_

#define LEN 15
#define MAXPOS 1000

typedef struct word {
	char s[LEN];
	unsigned int amount;
} Word;
typedef struct node {
	Word word;
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
unsigned int SizeTree(const Tree *ptree);
_Bool AddWord(const Word *pw, Tree *ptree);
Node *FindWord(const Word *pw, const Tree *ptree);
void Execute(const Tree *ptree, void (*pfun)(Word word));
void DeleteTree(Tree *ptree);

#endif
