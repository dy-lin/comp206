#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include "fork.h"

//Partner's name: Isidora Duma

int main(){

	int pid;
	FILE *turn;

	turn = fopen("TURN.txt","w");
	fprintf(turn,"0");
	fclose(turn);
	pid = fork();

	if (pid < 0)
		exit(1);
	
	if (pid == 0){
		producer();
		wait(NULL);
	}

	if (pid != 0){
		consumer();
		wait(NULL);
	}

}

