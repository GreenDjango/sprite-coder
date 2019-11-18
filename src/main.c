#include <stdio.h>
#include <unistd.h>
#include "bitmap.h"

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
	if (bitmap_open(&bitmap, argv[1]) == 0)
	{
		// TODO: initialize graphical env.
		bitmap_close(&bitmap);
		return (0);
	}
	return (84);
}
