#include "editor.h"
#include "display.h"

#if defined(GLIB_CSFML)
void editor_event(void)
{
	extern struct csfml_info_s csfml_info;

	while (sfRenderWindow_pollEvent(csfml_info.window, &csfml_info.event))
	{
		if (csfml_info.event.type == sfEvtClosed)
			sfRenderWindow_close(csfml_info.window);
	}
}
#else
	#error "No graphical library specified"
#endif
