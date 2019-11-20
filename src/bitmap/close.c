#include "bitmap.h"
#include <errno.h>

#if defined(BLIB_CSFML)
int bitmap_close(bitmap_t *bitmap)
{
	// Check potantial error.
	if (bitmap->private == NULL)
		return (EFAULT);

	// Free'd allocated spaces.
	sfImage_destroy(bitmap->private);
	return (0);
}

#elif defined(BLIB_CUSTOM)
// Include internal header.
#include <stdlib.h>

int bitmap_close(bitmap_t *bitmap)
{
	// Check potantial error.
	if (bitmap->private == NULL)
		return (EFAULT);

	// Free'd allocated spaces.
	free(bitmap->private);
	return (0);
}
#else
	#error "error: no bitmap library specified"
#endif
