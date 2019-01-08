all: main

main: main.o
	gcc -lpthread -g -o main main.o

main.o: main.c
	gcc -lpthread -g -c main.c

clean:
	rm *.o main *.out

clear:
	clear

success:
	$(info SUCCESS) 
