#include <stdio.h>
#include <unistd.h>
#include "bitmap.h"
#include "display.h"
#include "editor.h"
#include "clock.h"

/* For now the main is used for testing. */
int main(int argc, char* argv[])
{
	bitmap_t bitmap;

	// Check bitmap file.
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Bitmap file missing !\n");
		return (84);
	}

	// Open bitmap file.
	if (bitmap_open(&bitmap, argv[1]) != 0)
		return (84);
		
	// Initialize abstraction layer part.
	display_initialize(800, 920);
	clock_initialize();

	// Call application entry.
	editor_entry(&bitmap, argv[1]);

	// Exit properly.
	clock_fini();
	display_fini();
	bitmap_close(&bitmap);
	return (0);
}
