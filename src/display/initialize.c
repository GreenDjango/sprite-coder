#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include "display.h"

#if defined(GLIB_CSFML)
// Create internal global used by the CSFML abstraction.
struct csfml_info_s csfml_info;

//
// display_initialize - CSFML lib
// Contruct the CSFML (internal) structure and
// request a X11 display.
//
int display_initialize(size_t width, size_t height)
{
	extern struct csfml_info_s csfml_info;

	// Create Video RAM.
	csfml_info.vram.size = width * height;
	csfml_info.vram.data = (uint32_t*)malloc(sizeof(uint32_t) * csfml_info.vram.size);
	if (csfml_info.vram.data == NULL)
	{
		dprintf(STDERR_FILENO, "display: Open VRAM alloc error !\n");
		return (EFAULT);
	}

	// Initialize VRAM.
	memset(csfml_info.vram.data, 0x00, sizeof(uint32_t) * csfml_info.vram.size);

	// Request new X11 display.
	csfml_info.mode.width = width;
	csfml_info.mode.height = height;
	csfml_info.mode.bitsPerPixel = 32;
	csfml_info.window = sfRenderWindow_create(csfml_info.mode, "Sprite-coder", sfResize | sfClose, NULL);
	if (csfml_info.window == NULL)
	{
		dprintf(STDERR_FILENO, "display: Open windows error.\n");
		return (EFAULT);
	}

	// Enable vertical synchro.
	sfRenderWindow_setVerticalSyncEnabled(csfml_info.window, sfTrue);

	return (0);
}
#else
	#error "No graphical library specified"
#endif
