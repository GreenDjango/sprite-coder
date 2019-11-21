#include "display.h"
#include <errno.h>

int display_clear_vram(uint32_t color)
{
	extern struct csfml_info_s csfml_info;

	// Check if the VRAM exist.
	if (csfml_info.vram.data == NULL)
		return (EAGAIN);
		
	// Clear VRAM and return.
	for (size_t i = 0 ; i < csfml_info.vram.size ; i = i + 1)
		csfml_info.vram.data[i] = color;
	return (0);
}
