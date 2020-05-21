#ifndef function_H_
#define function_H_

#define CLEAR 0x00
#define OFF 0
#define ON 1
#define LEFT 0
#define CENTER 1
#define RIGHT 2

struct setFont {
	unsigned int type : 8;
	unsigned int size : 7;
	unsigned int align : 2;
	_Bool B : 1;
	_Bool I : 1;
	_Bool U : 1;
};

typedef void (*V_FONT)(struct setFont *); 

int convertBin(char *);
void displayBinar(const char *);
void bitwiseOp(const char *bin1, const char* bin2, char mode);
int countBiteOn(int);
_Bool getBit(int number, int n);
char turn(char ch, int n);
int menu(struct setFont *);
void setType(struct setFont *font);
void setSize(struct setFont *font);
void setAlign(struct setFont *font);
void setBold(struct setFont *font);
void setItalic(struct setFont *font);
void setUnderline(struct setFont *font);

#endif
