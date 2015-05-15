int heapMaximum(int *array);
int heapExtractMax(int *array, int heapSize);
void heapIncreaseKey(int *array, int i, int key);
void maxHeapInsert(int *array, int key, int heapSize);
void maxHeapify(int *array, int i, int heapSize);
int parent(int i);
int left(int i);
int right(int i);