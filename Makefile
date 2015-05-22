CFLAGS=-Wall -g

all:
	gcc -o Homework4 Homework4.c PriorityQueue.c PriorityQueue.h HeapSort.c HeapSort.h -lm
	gcc -o TestHomework4 TestHomework4.c -lm
	
run: 
	./Homework4 start

clean:
	rm -f queue
