#include <stdbool.h>
#include "min_heap.c"
#include "Libraries/unit_testing.c"

bool test_min_heap_with_one_element()
{
	MinHeap heap = { .quantity = 0 };
	add_to_heap(7, &heap);

	return heap.elements[0] == 7;
}

void run_all_tests()
{
	run_test(test_min_heap_with_one_element, "adding `7` should return [`7`]");
}

int main()
{
	run_all_tests();

	return 0;
}