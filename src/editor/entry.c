#include "editor.h"
#include "display.h"
#include "clock.h"

void editor_entry(bitmap_t *bitmap, char const *path)
{
	extern void clock_refresh(void); // <- private internal function.
	int clock_event;
	int clock_sync;

	// Not used for now.
	(void)bitmap;
	(void)path;

	// Create all clock.
	clock_sync = clock_create(31, &editor_render, NULL);	// 32hz
	clock_event = clock_create(16, &editor_event, NULL);	// 64hz

	// Useless loop, wait util the display is open.
	while (display_isActive() == 1)
	{
		// @note: due to CSFML / SFML limitation we can not
		// wrap callback with a clock.
		// So, we check manually each clock created to execute
		// her callback.
		// TODO: use fork !
		clock_refresh();
	}

	// Destroy all clock created during application's job.
	clock_destroy(clock_sync);
	clock_destroy(clock_event);
}
