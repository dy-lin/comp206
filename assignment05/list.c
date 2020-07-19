//DIANA LIN 260625972

#include "list.h"
#include <stdio.h>
#include <stdlib.h>

struct NODE* head;

//this linked list is private as the global pointer is declared in this file and not the header file

void newList(){
    head = NULL;
}

int addNode(int i) {
    struct NODE* newNode = (struct NODE*) malloc(sizeof(struct NODE));
    if (newNode == NULL) {
        return EXIT_FAILURE;
    }
    newNode->data = i;
    if (head == NULL) { //this means this node is the first node in the linked list
        newNode->next = NULL;
        head = newNode;
    }
    else {
        newNode->next = head;
        head = newNode;
    }
    return EXIT_SUCCESS;
    
}

void prettyPrint() { 
    struct NODE* temp = head;
    while (temp !=NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    if (temp != NULL) {
        printf("\n");
    }
}
