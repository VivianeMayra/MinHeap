#include <stdio.h>
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

void swap_numbers_in_heap(MinHeap *heap, int first_index, int second_index)
{
	int aux = heap->elements[first_index].value;
	heap->elements[first_index].value = heap->elements[second_index].value;
	heap->elements[second_index].value = aux;
}

void add_to_heap(int number, MinHeap *heap)
{
	HeapElement element = { .value = number };
	element.level = (int) log2(heap->quantity + 1);

	push_to_heap(element, heap);

	int number_index = heap->quantity - 1;
	int parent_index = 0;

	HeapElement parent = heap->elements[parent_index];

	if (number < parent.value)
		swap_numbers_in_heap(heap, number_index, parent_index);
}

void push_to_heap(HeapElement element, MinHeap *heap)
{
	int index_to_put = heap->quantity;
	heap->elements[index_to_put] = element;
	heap->quantity++;
}
