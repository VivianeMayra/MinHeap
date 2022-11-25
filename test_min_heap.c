#include <stdbool.h>
#include "min_heap.c"
#include "Libraries/unit_testing.c"

bool test_adding_one_number_to_min_heap()
{
	MinHeap heap = { .quantity = 0 };
	add_to_heap(7, &heap);

	return heap.elements[0] == 7;
}

bool test_adding_two_numbers_to_min_heap()
{
	MinHeap heap = { .quantity = 0 };
	add_to_heap(7, &heap);
	add_to_heap(8, &heap);

	return heap.elements[0] == 7 && heap.elements[1] == 8;
}

bool test_adding_multiple_numbers_to_min_heap()
{
	MinHeap heap = { .quantity = 0 };
	add_to_heap(7, &heap);
	add_to_heap(8, &heap);
	add_to_heap(9, &heap);
	add_to_heap(10, &heap);
	add_to_heap(11, &heap);

	return heap.elements[0] == 7
		&& heap.elements[1] == 8
		&& heap.elements[2] == 9
		&& heap.elements[3] == 10
		&& heap.elements[4] == 11;
}

void run_all_tests()
{
	run_test(test_adding_one_number_to_min_heap, "adding `7` should return `{ 7 }`");
	run_test(test_adding_two_numbers_to_min_heap, "adding `7` then `8` should return `{ 7, 8 }`");
	run_test(test_adding_multiple_numbers_to_min_heap, "adding `7` then `8`, `9`, `10`, `11` should return `{ 7, 8, 9, 10, 11 }`");
}

int main()
{
	run_all_tests();

	return 0;
}
