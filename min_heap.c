#define CAPACITY 200

typedef struct
{
	int elements[CAPACITY];
	int quantity;
} MinHeap;

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

	if (heap->elements[0] > heap->elements[1] && heap->quantity >= 2)
		swap_numbers_in_heap(heap, 0, 1);
}
