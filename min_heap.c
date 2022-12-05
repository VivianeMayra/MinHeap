#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "min_heap.h"

void _print_minheap(MinHeap *heap)
{
	printf("Heap: { ");

	for (int i = 0; i < heap->quantity - 1; i++)
		printf("%d, ", heap->elements[i].value);

	int last_index = heap->quantity - 1;
	int last_number = heap->elements[last_index].value;

	if (heap->quantity > 0)
		printf("%d", last_number);

	printf(" }\n");
}

static void swap_numbers_in_heap(MinHeap *heap, int index_1, int index_2)
{
	int number_1 = heap->elements[index_1].value;
	int number_2 = heap->elements[index_2].value;

	heap->elements[index_1].value = number_2;
	heap->elements[index_2].value = number_1;
}

static void push_to_heap(HeapElement element, MinHeap *heap)
{
	int last_index = heap->quantity - 1;
	heap->elements[last_index + 1] = element;

	heap->quantity++;
}

void add_to_heap(int number, MinHeap *heap)
{
	HeapElement element = { .value = number };
	element.level = (int) log2(heap->quantity + 1);

	push_to_heap(element, heap);

	int last_index = heap->quantity - 1;

	int index_of_element = last_index;

	bool element_is_root = (index_of_element == 0 ? true : false);
	while (!element_is_root)
	{
		int index_of_parent = (int) ((index_of_element - 1) / 2);
		HeapElement parent = heap->elements[index_of_parent];

		if (number < parent.value)
			swap_numbers_in_heap(heap, index_of_element, index_of_parent);
		else
			break;

		index_of_element = index_of_parent;
	}
}
