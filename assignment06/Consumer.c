#include<stdlib.h>
#include<stdio.h>

void consumer() {
    int turn, pos, x;
    char c, b;
        FILE *read;
        FILE *write;
        pos = 1;
        c = ' ';
        b = ' ';
        do {
                x = 1;
                while((write=fopen("TURN.txt","r")) != NULL){
                        c = fgetc(write);
                        fclose(write);
                        if(c == '1'){
                                break;
                        }
                }
                read=fopen("DATA.txt","r");


                b = fgetc(read);
                printf("%c",b);

                fclose(read);

                write = fopen("TURN.txt","r");
                if((c=fgetc(write)) == '2')
                        break;
                fclose(write);
                write = fopen("TURN.txt","w");
                fprintf(write,"0");
                fclose(write);
        } while (1);
}

