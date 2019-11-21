#include "display.h"

#if defined(GLIB_CSFML)
int display_isActive(void)
{
	extern struct csfml_info_s csfml_info;
	return (sfRenderWindow_isOpen(csfml_info.window));
}
#else
	#error "No graphical library specified"
#endif
