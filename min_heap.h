#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#define HEAP_CAPACITY 200

#define out

typedef struct
{
	int elements[HEAP_CAPACITY];
	int quantity;
} MinHeap;

void _print_minheap(MinHeap *);
void add_to_heap(int, MinHeap *);
void list_heap_in_ascending_order(MinHeap, out int[]);

#endif // MIN_HEAP_H
