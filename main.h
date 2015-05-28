struct Tuple
{
    char value;
    int priority;
};

void queue(int *priorityArray, struct Tuple *tuple_list, int *heapSize);

void printQueue(int *array, int heapSize);

void swapTuples(struct Tuple *tuple_list, int *array, int heapSize, int cases);

void commands(int command, int value, int priority, int *priorityArray, int *heapSize, struct Tuple *tuple_list);

void raisePriority(int value, int priority, int *priorityArray, int *heapSize, struct Tuple *tuple_list);
