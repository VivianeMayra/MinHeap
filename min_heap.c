#include <stdio.h>
#include "min_heap.h"

void _print_minheap(MinHeap *heap)
{
	printf("Heap: { ");

	for (int i = 0; i < heap->quantity - 1; i++)
		printf("%d, ", heap->elements[i]);

	int last_index = heap->quantity - 1;
	int last_element = heap->elements[last_index];

	if (heap->quantity > 0)
		printf("%d", last_element);

	printf(" }\n");
}

void swap_numbers_in_heap(MinHeap *heap, int first_index, int second_index)
{
	int aux = heap->elements[first_index];
	heap->elements[first_index] = heap->elements[second_index];
	heap->elements[second_index] = aux;
}

void add_to_heap(int number, MinHeap *heap)
{
	int index_to_put = heap->quantity;
	heap->elements[index_to_put] = number;

	heap->quantity++;

	int parent = heap->elements[0];
	int left_child = heap->elements[1];

	if (parent > left_child && heap->quantity >= 2)
		swap_numbers_in_heap(heap, 0, 1);

	if (heap->quantity > 2)
	{
		int right_child = heap->elements[2];
		if (parent > left_child && heap->quantity >= 2)
			swap_numbers_in_heap(heap, 0, 2);
	}
}
