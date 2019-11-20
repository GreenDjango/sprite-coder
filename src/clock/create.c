#include "clock.h"

#if defined(GLIB_CSFML)
int clock_create(uint32_t timeout, void *callback, void *arg)
{
	extern struct clock_info_s clock_stack[CLOCK_STACK_SIZE];
	int i;

	// Find unused slot.
	for (i = 0 ; i < CLOCK_STACK_SIZE && clock_stack[i].private != NULL; i = i + 1);

	// Check error.
	if (i >= CLOCK_STACK_SIZE)
		return (-1);

	// Initialize new clock.
	clock_stack[i].arg = arg;
	clock_stack[i].timeout = timeout;
	clock_stack[i].callback = callback;
	clock_stack[i].private = sfClock_create();

	// Check initialization error.
	if (clock_stack[i].private == NULL)
		return (-1);
	return (0);
}
#else
	#error "No clock library specified"
#endif
