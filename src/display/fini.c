#include "display.h"
#include <stdlib.h>

#ifdef GLIB_CSFML
//
// display_fini() - CSFML lib
// Fow now, juste destroy the X11 dsplay.
//
void display_fini(void)
{
	extern struct csfml_info_s csfml_info;

	sfRenderWindow_destroy(csfml_info.window);
	free(csfml_info.vram.data);
}
#else
	#error "No graphical library specified"
#endif
