#include <stdio.h>
#include "min_heap.h"

void _print_minheap(MinHeap *heap)
{
	printf("Heap: { ");

	for (int i = 0; i < heap->quantity - 1; i++)
		printf("%d, ", heap->elements[i].value);

	int last_index = heap->quantity - 1;
	int last_element = heap->elements[last_index].value;

	if (heap->quantity > 0)
		printf("%d", last_element);

	printf(" }\n");
}

void swap_numbers_in_heap(MinHeap *heap, int first_index, int second_index)
{
	int aux = heap->elements[first_index].value;
	heap->elements[first_index].value = heap->elements[second_index].value;
	heap->elements[second_index].value = aux;
}

void add_to_heap(int number, MinHeap *heap)
{
	HeapElement element = { .value = number };

	int index_to_put = heap->quantity;
	heap->elements[index_to_put] = element;

	int number_index = index_to_put;
	int parent_index = 0;

	heap->quantity++;

	HeapElement parent = heap->elements[parent_index];

	if (number < parent.value)
	{
		int aux = number;
		heap->elements[index_to_put] = parent;
		heap->elements[parent_index].value = aux;
	}
}
