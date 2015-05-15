CFLAGS=-Wall -g

all:
	gcc -o queue Homework4.c PriorityQueue.c PriorityQueue.h

clean:
	rm -f queue
