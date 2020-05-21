#ifndef font_H_
#define font_H_

#define UNDERLINE 0x1
#define ITALIC 0x2
#define BOLD 0x4
#define A_CENTER 0x8
#define A_RIGHT 0x10
#define A_CLEAR 0x18
#define S_CLEAR 0xFE0
#define ADD_SIZE 0x1F
#define F_CLEAR 0xFF000
#define ADD_FONT 0x800

typedef void (*V_FONT)(unsigned long *);

int menu(unsigned long *);
void setType(unsigned long *);
void setSize(unsigned long *);
void setAlign(unsigned long *);
void setBold(unsigned long *);
void setItalic(unsigned long *);
void setUnderline(unsigned long *);

#endif
