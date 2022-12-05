#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#define HEAP_CAPACITY 200

typedef struct
{
	int elements[HEAP_CAPACITY];
	int quantity;
} MinHeap;

void _print_minheap(MinHeap *heap);
void add_to_heap(int number, MinHeap *heap);

#endif // MIN_HEAP_H
