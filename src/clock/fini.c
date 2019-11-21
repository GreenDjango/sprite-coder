#include "clock.h"

void clock_fini(void)
{
	extern struct clock_info_s clock_stack[CLOCK_STACK_SIZE];

	// Check all clock and destroy if needed.
	for (int i = 0 ; i < CLOCK_STACK_SIZE ; i = i + 1)
	{
		if (clock_stack[i].private != NULL)
			clock_destroy(i);
	}
}
