#include <stdlib.h>
#include <stdio.h>
#include "PriorityQueue.h"
#include "HeapSort.h"
#include "Main.h"

int main(int argc, char *argv[])
{   
	char *func = argv[1];
	int i;
	int newar[500];
	int heapSize = 0;
	
	struct Tuple tuple_list[500];
	
	//calls the function and gives it the parameters
    switch(func[0])
    {
    	case 'h': heapSize = argc - 2;
    			  //sets the arguments for the new array to pass to the function
    			  for(i = 0; i < heapSize; i++)
				  {
					newar[i + 1] = strtol(argv[i + 2], NULL, 10);
				  }
    			  buildMaxHeap(newar, heapSize);
    		break;
    	case 's': queue(newar, tuple_list, &heapSize);
    	default: puts("command not found");	
    }
    //prints out array
    for(i = 1; i <= heapSize; i++)
	{
		printf("%d ", newar[i]);
	}
	puts("\n");
	
	return 0;
}

void queue(int *newar, struct Tuple *tuple_list, int *heapSize)
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
		scanf("\n%c %c %d", &command, &value, &priority);
		
		if(command == 'I')//inserts a new value with a priority
		{
			maxHeapInsert(newar, priority,  heapSize);
			tuple_list[*heapSize].value = value;
			tuple_list[*heapSize].priority = priority;
			
			buildMaxHeap(newar, *heapSize);//restores the max heap
			
			printQueue(newar, *heapSize);

		}
		if(command == 'E')//extracts the max value with its priority
		{
			if(*heapSize >= 1)
			{		
				printf("Value: %c, Priority: %d\n", tuple_list[1].value, tuple_list[1].priority);
				heapExtractMax(newar, heapSize);

				printQueue(newar, *heapSize);
				
				swapTuples(tuple_list, newar, *heapSize, 1);
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
				for(i = 1; i <= *heapSize; i++)
				{	
					if(tuple_list[i].value == value)
					{
						num = tuple_list[i].priority;
						tuple_list[i].priority = priority;//changes priority in the tuple list
						for(j = 1; j <= *heapSize; j++)
						{
							if(newar[j] == num)
							{
								heapIncreaseKey(newar, j, priority);
								buildMaxHeap(newar, *heapSize);//restores the max heap
							}
						}		
					}
				
				}
			}	
			
			printQueue(newar, *heapSize);
		}
		if(command == 'M')//prints out the max priority
		{
			printf("Max Priority: %d", heapMaximum(newar));
		}
		
		buildMaxHeap(newar, *heapSize);
		
		swapTuples(tuple_list, newar, *heapSize, 0);

		puts("\n");
		
	}
	
}

void printQueue(int *array, int heapSize)
{
	int i;
	for(i = 1; i <= heapSize; i++)//prints out queue
	{
		printf("%d, ", array[i]);
	}
	
}

void swapTuples(struct Tuple *tuple_list, int *newar, int heapSize, int cases)
{
	struct Tuple tuple;
	int i;
	int j;
				
	for(i = 1; i <= heapSize; i++)//makes tuples_list priority mirror newar priority
	{
		for(j = i; j <= heapSize + cases; j++)
		{
			if(newar[i] == tuple_list[j].priority)
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