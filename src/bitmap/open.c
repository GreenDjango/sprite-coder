#include "bitmap.h"
#include <stdio.h>
#include <unistd.h>


#if defined(BLIB_CSFML)
int bitmap_open(bitmap_t *bitmap, const char *path)
{
	// Try to open bitmap.
	bitmap->private = sfImage_createFromFile(path);
	if (bitmap->private == NULL)
	{
		dprintf(STDERR_FILENO, "bitmap: open \"%s\" error !\n", path);
		return (-1);
	}

	// Get image informations.
	sfVector2u image_size = sfImage_getSize(bitmap->private);
	bitmap->height = image_size.y;
	bitmap->width = image_size.x;
	bitmap->bpp = 32;
	return (0);
}

#elif defined(BLIB_CUSTOM)
// Include internal header.
#include <fcntl.h>
#include <stdlib.h>

int bitmap_open(bitmap_t *bitmap, char const *path)
{
	struct bitmap_header_s header;
	struct bitmap_dib_s dib;
	int fd;

	// Open bitmap file
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		dprintf(STDERR_FILENO, "bitmap: open \"%s\" error !\n", path);
		return (-1);
	}

	//---
	// Check bitmap header
	//---
	lseek(fd, 0x00, SEEK_SET);
	if (read(fd, &header, sizeof(struct bitmap_header_s)) != sizeof(struct bitmap_header_s))
	{
		dprintf(STDERR_FILENO, "Bitmap format error !\n");
		return (-2);
	}
	// Check bitmap signature.
	if (!((header.magic[0] == 'B' && header.magic[1] == 'M') ||
		(header.magic[0] == 'B' && header.magic[1] == 'A') ||
		(header.magic[0] == 'C' && header.magic[1] == 'I') ||
		(header.magic[0] == 'C' && header.magic[1] == 'P') ||
		(header.magic[0] == 'I' && header.magic[1] == 'C') ||
		(header.magic[0] == 'P' && header.magic[1] == 'T')))
	{
		dprintf(STDERR_FILENO, "Bitmap signature error !\n");
		return (-3);
	}
	// Display informations
	printf("file size  = %do\n", BITMAP_CONV_BE_32(header.file_size));
	printf("reserved 0 = %#x\n", BITMAP_CONV_BE_16(header.reserved_0));
	printf("reserved 1 = %#x\n", BITMAP_CONV_BE_16(header.reserved_1));
	printf("data start = %#x\n", BITMAP_CONV_BE_32(header.data_offset));

	//---
	// Check DIB header.
	//---
	//FIXME: read DIB header size and select appropriate DIB structure.
	lseek(fd, 0x0e, SEEK_SET);
	if (read(fd, &dib, sizeof(struct bitmap_dib_s)) != sizeof(struct bitmap_dib_s))
	{
		dprintf(STDERR_FILENO, "Bitmap (DIB) format error !\n");
		return (-4);
	}
	// Check BITMAPCORHEADER or OS2XBITMAPCOREHEADER or BITMAPINFOHEADER validity.
	// TODO: handle corretly BITMAPINFOHEADER !
	if (dib.size != BITMAPCORHEADER &&
			dib.size != OS2XBITMAPCOREHEADER &&
			dib.size != BITMAPINFOHEADER)
	{
		dprintf(STDERR_FILENO, "Bitmap (DIB) header validity error (%d) !\n", dib.size);
	//	return (-5);
	}
	// Get bitmap informations.
	bitmap->width = dib.bitmap_width;
	bitmap->height = dib.bitmap_height;
	bitmap->bpp = dib.bpp;

	//[DEBUG] Display informations.
	printf("bitmap width  = %d\n", bitmap->width);
	printf("bitmap height = %d\n", bitmap->height);
	printf("bit per pixel = %d\n", bitmap->bpp);

	//---
	// Dump data
	//---
	// Create internal buffer.
	int data_size = (((bitmap->width * bitmap->bpp) / 8) + 1) * bitmap->height;
	bitmap->private = malloc(data_size);
	if (bitmap->private == NULL)
	{
		dprintf(STDERR_FILENO, "bitmap: open() - data alloc error !\n");
		return (-6);
	}
	// read data.
	lseek(fd, BITMAP_CONV_BE_32(header.data_offset), SEEK_SET);
	read(fd, bitmap->private, data_size);
	
	//[Debug] display real data size.
	printf("bitmap real data size = %do\n", data_size);

	// Close bitmap file
	close(fd);
	return (0);
}
#else
	#error "error: no bitmap library specified"
#endif
