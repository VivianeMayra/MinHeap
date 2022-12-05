#include <stdbool.h>
#include "min_heap.h"
#include "Libraries/unit_testing.c"

bool test_adding_one_number_to_min_heap(out MinHeap *actual_heap)
{
	MinHeap heap = { .quantity = 0 };
	add_to_heap(7, &heap);

	*actual_heap = heap;

	return heap.elements[0].value == 7;
}

bool test_adding_two_numbers_to_min_heap(out MinHeap *actual_heap)
{
	MinHeap heap = { .quantity = 0 };
	add_to_heap(7, &heap);
	add_to_heap(8, &heap);

	*actual_heap = heap;

	return heap.elements[0].value == 7 && heap.elements[1].value == 8;
}

bool test_adding_multiple_numbers_to_min_heap(out MinHeap *actual_heap)
{
	MinHeap heap = { .quantity = 0 };
	add_to_heap(7, &heap);
	add_to_heap(8, &heap);
	add_to_heap(9, &heap);
	add_to_heap(10, &heap);
	add_to_heap(11, &heap);

	*actual_heap = heap;

	return heap.elements[0].value == 7
		&& heap.elements[1].value == 8
		&& heap.elements[2].value == 9
		&& heap.elements[3].value == 10
		&& heap.elements[4].value == 11;
}

bool test_adding_adjacent_numbers_in_descending_order_to_min_heap(out MinHeap *actual_heap)
{
	MinHeap heap = { .quantity = 0 };
	add_to_heap(14, &heap);
	add_to_heap(10, &heap);

	*actual_heap = heap;

	return heap.elements[0].value == 10
		&& heap.elements[1].value == 14;
}

bool test_adding_numbers_in_descending_order_to_min_heap(out MinHeap *actual_heap)
{
	MinHeap heap = { .quantity = 0 };
	add_to_heap(14, &heap);
	add_to_heap(1, &heap);
	add_to_heap(10, &heap);

	*actual_heap = heap;

	return heap.elements[0].value == 1
		&& heap.elements[1].value == 14
		&& heap.elements[2].value == 10;
}

bool test_adding_numbers_in_descending_order_to_min_heap_with_two_reorderings(out MinHeap *actual_heap)
{
	MinHeap heap = { .quantity = 0 };
	add_to_heap(14, &heap);
	add_to_heap(11, &heap);
	add_to_heap(10, &heap);

	*actual_heap = heap;

	return heap.elements[0].value == 10
		&& heap.elements[1].value == 14
		&& heap.elements[2].value == 11;
}

bool test_adding_many_numbers_to_min_heap_with_multiple_reorderings(out MinHeap *actual_heap)
{
	MinHeap heap = { .quantity = 0 };
	add_to_heap(17, &heap);
	add_to_heap(10, &heap);
	add_to_heap(8, &heap);
	add_to_heap(9, &heap);
	add_to_heap(2, &heap);
	add_to_heap(1, &heap);

	*actual_heap = heap;

	return heap.elements[0].value == 1
		&& heap.elements[1].value == 8
		&& heap.elements[2].value == 2
		&& heap.elements[3].value == 17
		&& heap.elements[4].value == 9
		&& heap.elements[5].value == 10;
}

bool test_level_of_numbers_added_to_min_heap(out MinHeap *actual_heap)
{
	MinHeap heap = { .quantity = 0 };

	for (int i = 0; i < 8; i++)
		add_to_heap(1, &heap);

	*actual_heap = heap;

	return heap.elements[0].level == 0
		&& heap.elements[1].level == 1
		&& heap.elements[2].level == 1
		&& heap.elements[3].level == 2
		&& heap.elements[4].level == 2
		&& heap.elements[5].level == 2
		&& heap.elements[6].level == 2
		&& heap.elements[7].level == 3;
}

void run_all_tests()
{
	run_test(test_adding_one_number_to_min_heap, "adding `7` should return `{ 7 }`");
	run_test(test_adding_two_numbers_to_min_heap, "adding `7` then `8` should return `{ 7, 8 }`");
	run_test(test_adding_multiple_numbers_to_min_heap, "adding `7` then `8`, `9`, `10`, `11` should return `{ 7, 8, 9, 10, 11 }`");

	run_test(test_adding_adjacent_numbers_in_descending_order_to_min_heap, "adding `14` then `10` should return `{ 10, 14 }`");
	run_test(test_adding_numbers_in_descending_order_to_min_heap, "adding `14` then `1`, `10` should return `{ 1, 14, 10 }`");
	run_test(test_adding_numbers_in_descending_order_to_min_heap_with_two_reorderings, "adding `14` then `11`, `10` should return `{ 10, 14, 11 }`");
	run_test(test_adding_many_numbers_to_min_heap_with_multiple_reorderings, "adding `17` then `10`, `8`, `9`, `2`, `1` should return `{ 1, 8, 2, 17, 9, 10 }`");

	run_test(test_level_of_numbers_added_to_min_heap, "elements on first row should have level 0; those on the second, level 1; those on the third, level 2");
}

int main()
{
	run_all_tests();

	return 0;
}
