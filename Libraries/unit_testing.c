#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../min_heap.h"

#define out

void run_test(bool (*testing_function)(), char *message)
{
	MinHeap *actual_heap = malloc(sizeof (MinHeap));

	if (testing_function(out actual_heap))
	{
		printf("\x1b[32m" "PASSED" "\x1b[0m" ": %s\n", message);
	}
	else
	{
		printf("\x1b[31m" "FAILED" "\x1b[0m" ": %s\n", message);
		printf("\t" "Got: ");
		_print_minheap(actual_heap);
	}
}
