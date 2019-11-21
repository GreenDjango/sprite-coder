#include "clock.h"

#if defined(GLIB_CSFML)
uint32_t clock_getTime(int clock_id)
{
	extern struct clock_info_s clock_stack[CLOCK_STACK_SIZE];

	// Check potential erorr.
	if (clock_id < 0 || clock_id >= CLOCK_STACK_SIZE)
		return (-1);

	// Check if the timer is currently used or not
	if (clock_stack[clock_id].private == NULL)
		return (-2);

	// Return elapsed time (microseconds)
	return ((uint32_t)sfClock_getElapsedTime(clock_stack[clock_id].private).microseconds);
}
#else
	#error "No clock library specified"
#endif
