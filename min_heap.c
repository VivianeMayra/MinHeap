#define CAPACITY 200

typedef struct
{
	int elements[CAPACITY];
	int quantity;
} MinHeap;

void add_to_heap(int number, MinHeap *heap)
{
	int index_to_put = heap->quantity;
	heap->elements[index_to_put] = number;

    heap->quantity++;
}
