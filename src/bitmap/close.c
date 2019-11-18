#include "bitmap.h"
#include <unistd.h>
#include <stdlib.h>

int bitmap_close(bitmap_t *bitmap)
{
	// Free'd allocated spaces.
	if (bitmap->data != NULL)
		free(bitmap->data);
	return (0);
}
