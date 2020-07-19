//DIANA LIN 260625972

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
int main() {
    int n;
    newList();
    printf("Input a number: ");
    scanf("%d", &n);
    while (n>0) {
        addNode(n);
        printf("Input a number: ");
        scanf("%d", &n);
        
    }
    prettyPrint();
    return 0;
}
