#include "clock.h"

// clock_refresh() - Common
// private function of clock module.
// Check all clock and excecute callcack if needed.
void clock_refresh(void)
{
	extern struct clock_info_s clock_stack[CLOCK_STACK_SIZE];

	for (int i = 0 ; i < CLOCK_STACK_SIZE ; i = i + 1)
	{
		// Check if the clock exist or not.
		if (clock_stack[i].private == NULL)
			continue;

		// Check elapsed time.
		if (clock_getTime(i) < clock_stack[i].timeout)
			continue;

		//involve callback and restart the clock.
		clock_stack[i].callback(clock_stack[i].arg);
		clock_restart(i);
	}
}
