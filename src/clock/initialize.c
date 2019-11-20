#include "clock.h"

// Create internal global used by the clock API.
struct clock_info_s clock_stack[CLOCK_STACK_SIZE];

//
// clock_initialize() - Common lib.
// Common clock abstraction initialization.
//
int clock_initialize(void)
{
	// Initialize internal stack.
	for (int i = 0 ; i < CLOCK_STACK_SIZE ; i = i + 1)
	{
		clock_stack[i].callback = NULL;
		clock_stack[i].private = NULL;
	}
	return (0);
}
