#include "clock.h"

#if defined(GLIB_CSFML)
int clock_restart(int clock_id)
{
	extern struct clock_info_s clock_stack[CLOCK_STACK_SIZE];

	// Check potential erorr.
	if (clock_id < 0 || clock_id >= CLOCK_STACK_SIZE)
		return (-1);

	// Check if the timer is currently used or not
	if (clock_stack[clock_id].private == NULL)
		return (-2);

	// Restart clock and return 0
	sfClock_restart(clock_stack[clock_id].private);
	return (0);
}
#else
	#error "No clock library specified"
#endif
