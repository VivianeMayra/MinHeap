#include <stdio.h>
#include <stdbool.h>

void run_test(bool (*testing_function)(), char *message)
{
	if (testing_function())
		printf("\x1b[32m" "PASSED" "\x1b[0m" ": %s\n", message);
	else
		printf("\x1b[31m" "FAILED" "\x1b[0m" ": %s\n", message);
}
