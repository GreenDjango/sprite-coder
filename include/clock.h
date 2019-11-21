#ifndef __CLOCK_H__
# define __CLOCK_H__

#include <stddef.h>
#include <stdint.h>

// Clock library specifique informations.
#if defined(GLIB_CSFML)
	// Include all CSFML specific header.
	#include <SFML/System.h>
#else
	#error "No clock library specified"
#endif

// Internal parameter.
#ifndef CLOCK_STACK_SIZE
	#define CLOCK_STACK_SIZE	(4)
#endif

// Define internal clock data structure.
struct clock_info_s
{
	void (*callback)(volatile void *arg);
	volatile void *arg;
	uint32_t timeout;
	void *private;
};

// Constructor / destructor.
extern int clock_initialize(void);
extern void clock_fini(void);

// General abstractions
extern int clock_create(uint32_t timeout, void *callback, void *arg);
extern uint32_t clock_getTime(int clock_id);
extern int clock_restart(int clock_id);
extern int clock_destroy(int clock_id);

#endif /*__CLOCK_H__*/
