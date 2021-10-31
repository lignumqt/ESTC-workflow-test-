all: vector

vector: main.o
	gcc -o vector main.o

main.o: main.c
	gcc -c -g -o main.o main.c

.PHONY: clean

clean:
	rm vector