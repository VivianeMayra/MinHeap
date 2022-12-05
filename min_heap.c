#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "min_heap.h"

void _print_minheap(MinHeap *heap)
{
	printf("Heap: { ");

	for (int i = 0; i < heap->quantity - 1; i++)
		printf("%d, ", heap->elements[i]);

	int last_index = heap->quantity - 1;
	int last_number = heap->elements[last_index];

	if (heap->quantity > 0)
		printf("%d", last_number);

	printf(" }\n");
}

static void swap_numbers_in_heap(MinHeap *heap, int index_1, int index_2)
{
	int number_1 = heap->elements[index_1];
	int number_2 = heap->elements[index_2];

	heap->elements[index_1] = number_2;
	heap->elements[index_2] = number_1;
}

static void push_to_heap(int number, MinHeap *heap)
{
	int last_index = heap->quantity - 1;
	heap->elements[last_index + 1] = number;

	heap->quantity++;
}

void add_to_heap(int number, MinHeap *heap)
{
	push_to_heap(number, heap);

	int last_index = heap->quantity - 1;
	int index_of_number = last_index;

	bool element_is_root = (index_of_number == 0 ? true : false);
	while (!element_is_root)
	{
		int index_of_parent = (int) ((index_of_number - 1) / 2);
		int parent = heap->elements[index_of_parent];

		if (number < parent)
			swap_numbers_in_heap(heap, index_of_number, index_of_parent);
		else
			break;

		index_of_number = index_of_parent;
	}
}
