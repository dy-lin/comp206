#include<stdio.h>
#include<stdlib.h>

void producer(){

        FILE *my_file, *turn, *data;
        char c, b;

        c = ' ';
        b = ' ';

        my_file = fopen("mydata.txt", "r+");
        while((b = fgetc(my_file)) != EOF){

                while((turn = fopen("TURN.txt", "r")) != NULL){
                        c = fgetc(turn);
                        fclose(turn);
                        if(c == '0')
                                break;
                }

                data = fopen("DATA.txt", "w");
                fprintf(data,"%c",b);
                fclose(data);

                turn = fopen("TURN.txt","w");
                fprintf(turn,"1");
                fclose(turn);

        }

        turn = fopen("TURN.txt", "w");
        fprintf(turn, "2");
        fclose(turn);

        fclose(my_file);


}
