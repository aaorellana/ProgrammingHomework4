void buildMaxHeap(int *array, int heapSize);
int heapMaximum(int *array);
void maxHeapify(int *array, int i, int heapSize);
int parent(int i);
int left(int i);
int right(int i);
void swap(int *array, int i, int j);