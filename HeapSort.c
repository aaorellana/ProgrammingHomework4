#include "HeapSort.h"
#include <limits.h>
#include <math.h>


void buildMaxHeap(int *array, int heapSize)
{
	int i;

	for(i = ceil(heapSize / 2); i >= 1; i--)
	{
		maxHeapify(array, i, heapSize);
	}
}

int heapMaximum(int *array)
{
	return array[1];
}


void maxHeapify(int *array, int i, int heapSize)
{
	int l;
	int r;
	int largest;
	l = left(i);
	r = right(i);
	if((l <= heapSize) && (array[l] > array[i]))
	{
		largest = l;
	}
	else
	{
		largest = i;
	}
	if((r <= heapSize) && (array[r] > array[largest]))
	{
		largest = r;
	}
	if(largest != i)
	{
		swap(array, i, largest);
		maxHeapify(array, largest, heapSize); 
	}
	
}

int parent(int i)
{
	return i / 2;
}

int left(int i)
{
	return 2 * i;
}

int right(int i)
{
	return 2 * i + 1;
}

void swap(int *array, int i, int j)
{
	int temp;

	temp = array[j];
	array[j] = array[i];
	array[i] = temp;
	
}
