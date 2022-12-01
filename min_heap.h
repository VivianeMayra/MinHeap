#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#define CAPACITY 200

typedef struct
{
	int elements[CAPACITY];
	int quantity;
} MinHeap;

void _print_minheap(MinHeap *heap);
void swap_numbers_in_heap(MinHeap *heap, int first_index, int second_index);
void add_to_heap(int number, MinHeap *heap);

#endif // MIN_HEAP_H
