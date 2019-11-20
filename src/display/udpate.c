#include "display.h"

#if defined(GLIB_CSFML)
void display_update(void)
{
	extern struct csfml_info_s csfml_info;

	sfRenderWindow_display(csfml_info.window);
}
#else
	#error "No graphical library specified"
#endif
