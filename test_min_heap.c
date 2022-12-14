#include <stdbool.h>
#include "min_heap.h"
#include "Libraries/unit_testing.c"

bool test_adding_one_number_to_min_heap(out MinHeap *actual_heap)
{
	MinHeap heap = { .quantity = 0 };
	add_to_heap(7, &heap);

	*actual_heap = heap;

	return heap.elements[0] == 7;
}

bool test_adding_two_numbers_to_min_heap(out MinHeap *actual_heap)
{
	MinHeap heap = { .quantity = 0 };
	add_to_heap(7, &heap);
	add_to_heap(8, &heap);

	*actual_heap = heap;

	return heap.elements[0] == 7 && heap.elements[1] == 8;
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

	return heap.elements[0] == 7
		&& heap.elements[1] == 8
		&& heap.elements[2] == 9
		&& heap.elements[3] == 10
		&& heap.elements[4] == 11;
}

bool test_adding_adjacent_numbers_in_descending_order_to_min_heap(out MinHeap *actual_heap)
{
	MinHeap heap = { .quantity = 0 };
	add_to_heap(14, &heap);
	add_to_heap(10, &heap);

	*actual_heap = heap;

	return heap.elements[0] == 10
		&& heap.elements[1] == 14;
}

bool test_adding_numbers_in_descending_order_to_min_heap(out MinHeap *actual_heap)
{
	MinHeap heap = { .quantity = 0 };
	add_to_heap(14, &heap);
	add_to_heap(1, &heap);
	add_to_heap(10, &heap);

	*actual_heap = heap;

	return heap.elements[0] == 1
		&& heap.elements[1] == 14
		&& heap.elements[2] == 10;
}

bool test_adding_numbers_in_descending_order_to_min_heap_with_two_reorderings(out MinHeap *actual_heap)
{
	MinHeap heap = { .quantity = 0 };
	add_to_heap(14, &heap);
	add_to_heap(11, &heap);
	add_to_heap(10, &heap);

	*actual_heap = heap;

	return heap.elements[0] == 10
		&& heap.elements[1] == 14
		&& heap.elements[2] == 11;
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

	return heap.elements[0] == 1
		&& heap.elements[1] == 8
		&& heap.elements[2] == 2
		&& heap.elements[3] == 17
		&& heap.elements[4] == 9
		&& heap.elements[5] == 10;
}

bool test_listing_heap_with_one_element()
{
	MinHeap heap;

	heap.elements[0] = 10;
	heap.quantity = 1;

	int list[1];
	list_heap_in_ascending_order(heap, out list);

	return list[0] == 10;
}

bool test_listing_heap_with_already_ordered_elements()
{
	MinHeap heap;

	heap.elements[0] = 1;
	heap.elements[1] = 2;
	heap.elements[2] = 3;
	heap.elements[3] = 7;
	heap.elements[4] = 8;
	heap.elements[5] = 9;
	heap.quantity = 6;

	int list[6];
	list_heap_in_ascending_order(heap, out list);

	return list[0] == 1
		&& list[1] == 2
		&& list[2] == 3
		&& list[3] == 7
		&& list[4] == 8
		&& list[5] == 9;
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

	run_test(test_listing_heap_with_one_element, "listing the heap `{ 10 }` should return the vector `{ 10 }`");
	run_test(test_listing_heap_with_already_ordered_elements, "listing the heap `{ 1, 2, 3, 7, 8, 9 }` should return the vector `{ 1, 2, 3, 7, 8, 9 }`");
}

int main()
{
	run_all_tests();

	return 0;
}
