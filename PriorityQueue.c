#include <limits.h>

int heapMaximum(int *array);
int heapExtractMax(int *array, int heapSize);
void heapIncreaseKey(int *array, int i, int key);
void maxHeapInsert(int *array, int key, int heapSize);
void maxHeapify(int *array, int i, int heapSize);
int parent(int i);
int left(int i);
int right(int i);


int heapMaximum(int *array)
{
	return array[0];
}

int heapExtractMax(int *array, int heapSize)
{
	int max;
	
	if(heapSize < 1)
	{
		puts("error heap underflow");
	}
	
	max = array[1];
	array[1] = array[heapSize];
	heapSize = heapSize - 1;
	maxHeapify(array, 0, heapSize);
	return max;
}

void heapIncreaseKey(int *array, int i, int key)
{
	if(key < array[i])
	{
		puts("new key is smaller than current key");
	}
	array[i] = key;
	while(i > 1 && array[parent(i) < array[i]])
	{
		//swap(array, array[i], array[parent]);
		i = parent(i);
	}
	
		
}

void maxHeapInsert(int *array, int key, int heapSize)
{
	heapSize = heapSize + 1;
	array[heapSize] = INT_MIN;
	heapIncreaseKey(array, heapSize, key);
}

void maxHeapify(int *array, int i, int heapSize)
{
	int l;
	int r;
	int largest;
	l = left(i);
	r = right(i);
	if((l <= heapSize) && array[l] > array[r])
	{
		largest = l;
	}
	else
	{
		largest = i;
	}
	if((r <= heapSize) && array[r] > array[largest])
	{
		largest = r;
	}
	if(largest != i)
	{
		//swap(array, array[i], array[largest]);
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