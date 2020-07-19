//DIANA LIN 260625972

#ifndef LIST_H
#define LIST_H
struct NODE {
    int data;
    struct NODE *next;
};

//function prototypes

void newList();
int addNode(int value);
void prettyPrint();
#endif
