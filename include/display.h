#ifndef __DISPLAY_H__
# define __DISPLAY_H__

#include <stdint.h>
#include <stddef.h>

// Graphical library specifique informations.
#if defined(GLIB_CSFML)
	// Include all CSFML specific header.
	#include <SFML/Graphics.h>

	// Define internal CSFML data structure.
	struct csfml_info_s
	{
		sfEvent event;
		sfVideoMode mode;
		sfRenderWindow *window;
		struct {
			size_t size;
			uint32_t *data;
		} vram;
	};
#endif

//---
// API prototypes.
//---
// Constructor / destructor
extern int display_initialize(size_t width, size_t height);
extern void display_fini(void);

// Genearal abstractions.
extern int display_isActive(void);
extern int display_clear_vram(uint32_t color);
extern void display_clear_screen(uint32_t color);
extern void display_update(void);

#endif /*__DISPLAY_H__*/
