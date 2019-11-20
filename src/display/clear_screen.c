#include "display.h"

#if defined(GLIB_CSFML)
void display_clear_screen(uint32_t color)
{
	extern struct csfml_info_s csfml_info;

	sfRenderWindow_clear(csfml_info.window, *(sfColor*)&color);
}
#else
	#error "No graphical library specified"
#endif
