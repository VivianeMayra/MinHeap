#define CAPACITY 200

typedef struct
{
	int elements[CAPACITY];
	int quantity;
} MinHeap;

void add_to_heap(int number, MinHeap *heap)
{
	heap->elements[0] = number;
}