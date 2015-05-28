#include <stdlib.h>
#include <stdio.h>
#include "PriorityQueue.h"
#include "HeapSort.h"
#include "Main.h"

int main(int argc, char *argv[])
{   
	char *func = argv[1];
	int i;
	int priorityArray[500];
	int heapSize = 0;
	
	struct Tuple tuple_list[500];
	
	//calls the function and gives it the parameters
    switch(func[0])
    {
    	case 'h': heapSize = argc - 2;
    			  //sets the arguments for the new array to pass to the function
    			  for(i = 0; i < heapSize; i++)
				  {
					priorityArray[i + 1] = strtol(argv[i + 2], NULL, 10);
				  }
    			  buildMaxHeap(priorityArray, heapSize);
    		break;
    	case 's': queue(priorityArray, tuple_list, &heapSize);
    	default: puts("command not found");	
    }
    //prints out array
    for(i = 1; i <= heapSize; i++)
	{
		printf("%d ", priorityArray[i]);
	}
	puts("\n");
	
	return 0;
}

void queue(int *priorityArray, struct Tuple *tuple_list, int *heapSize)
{
	char value;
	int priority;
	char command;
	struct Tuple tuple;
	int i;
	int j;
	int num;
	
	while(1)
	{
		scanf("\n%c %c %d", &command, &value, &priority);//reads user input
		
		commands(command, value, priority, priorityArray, heapSize, tuple_list);//runs the appropriate command given

		buildMaxHeap(priorityArray, *heapSize);//heapifies the array
		
		swapTuples(tuple_list, priorityArray, *heapSize, 0);//mirrors the tuple array to the priority array

		puts("\n");
		
	}
	
}

void printQueue(int *array, int heapSize)//prints out queue
{
	int i;
	for(i = 1; i <= heapSize; i++)
	{
		printf("%d, ", array[i]);
	}
	
}

void swapTuples(struct Tuple *tuple_list, int *priorityArray, int heapSize, int cases)
{
	struct Tuple tuple;
	int i;
	int j;
				
	for(i = 1; i <= heapSize; i++)//makes tuples_list priority mirror priorityArray priority
	{
		for(j = i; j <= heapSize + cases; j++)
		{
			if(priorityArray[i] == tuple_list[j].priority)
			{	
				//swap tuples
				tuple.value = tuple_list[i].value;
				tuple.priority = tuple_list[i].priority;
				tuple_list[i].value = tuple_list[j].value;
				tuple_list[i].priority = tuple_list[j].priority;
				tuple_list[j].value = tuple.value;
				tuple_list[j].priority = tuple.priority;
			}
		}
	}				
}

void commands(int command, int value, int priority, int *priorityArray, int *heapSize, struct Tuple *tuple_list)
{
	int i;
	int j;
	int num;
	if(command == 'I')//inserts a new value with a priority
	{
		maxHeapInsert(priorityArray, priority,  heapSize);
		tuple_list[*heapSize].value = value;
		tuple_list[*heapSize].priority = priority;
			
		buildMaxHeap(priorityArray, *heapSize);//restores the max heap
			
		printQueue(priorityArray, *heapSize);

	}
	if(command == 'E')//extracts the max value with its priority
	{
		if(*heapSize >= 1)
		{		
			printf("Value: %c, Priority: %d\n", tuple_list[1].value, tuple_list[1].priority);
			heapExtractMax(priorityArray, heapSize);

			printQueue(priorityArray, *heapSize);
				
			swapTuples(tuple_list, priorityArray, *heapSize, 1);
		}
		else
		{
			puts("There is nothing else to extract");
		}	
	}
	if(command == 'R')//increases the priority R A 8 increases A with the priority of 8
	{
		if(*heapSize >= 1)
		{
			raisePriority(value, priority, priorityArray, heapSize, tuple_list);
		}	
			
		printQueue(priorityArray, *heapSize);
		}
		if(command == 'M')//prints out the max priority
		{
			printf("Max Priority: %d", heapMaximum(priorityArray));
		}
}

void raisePriority(int value, int priority, int *priorityArray, int *heapSize, struct Tuple *tuple_list)//raises the priority
{
	int i;
	int j;
	int num;
	
	for(i = 1; i <= *heapSize; i++)
	{	
		if(tuple_list[i].value == value)
		{
			num = tuple_list[i].priority;
			tuple_list[i].priority = priority;//changes priority in the tuple list
			for(j = 1; j <= *heapSize; j++)
			{
				if(priorityArray[j] == num)
				{
					heapIncreaseKey(priorityArray, j, priority);//changes the priority in the priority array
					buildMaxHeap(priorityArray, *heapSize);//restores the max heap
				}
			}		
		}
	}
	
}