#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "PriorityQueue.h"
#include "HeapSort.h"

struct Tuple
{
    char value;
    int priority;
};

void queue(int *newar, struct Tuple *tuple_list, int *heapSize);

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
	
	puts("Fully compiled!!!!!\n");
	return 0;
}

void queue(int *newar, struct Tuple *tuple_list, int *heapSize)
{
	char value;
	int priority;
	char command;
	struct Tuple tuple;
	int check;
	int i;
	int j;
	int num;
	
	while(1)
	{
  		
		scanf("\n%c %c %d", &command, &value, &priority);
		
		if(command == 'I')
		{
			maxHeapInsert(newar, priority,  heapSize);
			tuple_list[*heapSize].value = value;
			tuple_list[*heapSize].priority = priority;
		}
		if(command == 'E')
		{
			if(*heapSize >= 1)
			{		
				check = heapExtractMax(newar, heapSize);
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
							}
						}		
					}
				
				}
			}	

		}
		
	buildMaxHeap(newar, *heapSize);

	for(i = 1; i < *heapSize; i++)//makes tuples_list priority mirror newar priority
	{
			
		for(j = i + 1; j < *heapSize; j++)
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
	
	for(i = 1; i <= *heapSize; i++)
	{
		printf("%d, ", newar[i]);
	}
	puts("\n");
	
	for(i = 1; i <= *heapSize; i++)
	{
		printf("Tuple %d Value %c Priority %d, ", i, tuple_list[i].value, tuple_list[i].priority);
	}
	
	puts("\n");
		
	}
	
	
	
}
