#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "PriorityQueue.h"
#include "HeapSort.h"

int main(void)
{  
	int before_insert[1] = {0};
	int after_insert[2] = {0, 5};
	int before_extract_max[4] = {0, 5, 4, 1};
	int after_extract_max[3] = {0, 4, 1};
	int before_read_max[4] = {0, 5, 4, 1};
	int after_read_max[4] = {0, 5, 4, 1};
	int before_raise_priority4[4] = {0, 5, 4, 1};
	int after_raise_priority4[4] = {0, 6, 5, 1};
	int heapSize = 3;
	int test_num;
	
	//test inserting into a queue
	heapSize = 1;
	maxHeapInsert(before_insert, 5, &heapSize);
	assert(after_insert[1] == before_insert[1]);
	
	//tests the extract of a queue
	heapSize = 3;
	test_num = heapExtractMax(before_extract_max, &heapSize);
	assert(test_num == 5);
	assert(1 == test(before_extract_max, after_extract_max, 1, 2));
	
	//tests reading the max priority
	test_num = heapMaximum(before_read_max);
	assert(test_num == 5);
	assert(1 == test(before_read_max, after_read_max, 1, 3));
	
	//tests raising the priority
	heapIncreaseKey(before_raise_priority4, 2, 6);
	assert(1 == test(before_raise_priority4, after_raise_priority4, 1, 3));

	return 0;
}

int test(int *array1, int *array2, int begin, int end)
{
	int i;
	int passed = 1; //1 means true
	
	for(i = begin; i < end; i++)
	{
		if(array1[i] != array2[i])
		{
			passed = 0;
		}	
	}
	
	return passed;
}