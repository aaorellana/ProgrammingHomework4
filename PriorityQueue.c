#include "PriorityQueue.h"
#include <limits.h>


void heapIncreaseKey(int *array, int i, int key)
{
	if(key < array[i])
	{
		puts("new key is smaller than current key");
	}
	array[i] = key;
	while(i > 1 && array[parent(i) < array[i]])
	{
		swap(array, i, parent(i));
		i = parent(i);
	}
	
		
}

void maxHeapInsert(int *array, int key, int *heapSize)
{
	*heapSize = *heapSize + 1;
	array[*heapSize] = INT_MIN;
	heapIncreaseKey(array, *heapSize, key);
}

int heapExtractMax(int *array, int *heapSize)
{
	int max;
	
	if(*heapSize < 1)
	{
		puts("error heap underflow");
	}
	
	max = array[1];
	array[1] = array[*heapSize];
	*heapSize = *heapSize - 1;
	maxHeapify(array, 1, *heapSize);
	return max;
}


