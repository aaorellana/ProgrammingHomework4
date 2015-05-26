struct Tuple
{
    char value;
    int priority;
};

void queue(int *newar, struct Tuple *tuple_list, int *heapSize);

void printQueue(int *array, int heapSize);

void swapTuples(struct Tuple *tuple_list, int *array, int heapSize, int cases);
