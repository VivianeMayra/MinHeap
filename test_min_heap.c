#include <stdbool.h>
#include "min_heap.c"
#include "Libraries/unit_testing.c"

bool test_min_heap_with_one_element()
{
	MinHeap heap = { .quantity = 0 };
	add_to_heap(7, &heap);

	return heap.elements[0] == 7;
}

bool test_min_heap_with_two_elements()
{
	MinHeap heap = { .quantity = 0 };
	add_to_heap(7, &heap);
	add_to_heap(8, &heap);

	return heap.elements[0] == 7 && heap.elements[1] == 8;
}

void run_all_tests()
{
	run_test(test_min_heap_with_one_element, "adding `7` should return [`7`]");
	run_test(test_min_heap_with_two_elements, "adding `7` then `8` should return [`7`, `8`]");
}

int main()
{
	run_all_tests();

	return 0;
}