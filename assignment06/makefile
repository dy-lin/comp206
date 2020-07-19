program: Producer.o Consumer.o Main.o
	gcc -o program Producer.o Consumer.o Main.o
Producer.o: Producer.c
	gcc -c Producer.c
Consumer.o: Consumer.c
	gcc -c Consumer.c
Main.o: Main.c fork.h
	gcc -c Main.c
