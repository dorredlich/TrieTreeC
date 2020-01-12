CC = gcc
FLAGS = -Wall -g

all: frequency

frequency: main.o trie.o
	$(CC) $(FLAGS) -o frequency main.o trie.o

trie.o: trie.c trie.h
	$(CC) $(FLAGS) -c trie.c

main.o: main.c
	$(CC) $(FLAGS) -c main.c

.PHONY: clean all

clean:
	rm -f *.o frequency
	
