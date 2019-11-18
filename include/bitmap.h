#ifndef __BITMAP_H__
# define __BITMAP_H__

#include <stdint.h>
#include <stddef.h>

#define BITMAPCORHEADER		(12)
#define OS2XBITMAPCOREHEADER	(12)
#define BITMAPINFOHEADER	(40)

// Internal Big Endian helper.
#define BITMAP_CONV_BE_32(tab)	\
	((tab[0] << 0) | (tab[1] << 8) | (tab[2] << 16) | (tab[3] << 24))

#define BITMAP_CONV_BE_16(tab)	\
	((tab[0] << 0) | (tab[1] << 8))

struct bitmap_header_s
{
	uint8_t magic[2];
	uint8_t file_size[4];
	uint8_t reserved_0[2];
	uint8_t reserved_1[2];
	uint8_t data_offset[4];
};

struct bitmap_dib_s
{
	uint32_t size;
	uint32_t bitmap_width;
	uint32_t bitmap_height;
	uint16_t plane;
	uint16_t bpp;
};

typedef struct bitmap_s
{
	uint16_t width;
	uint16_t height;
	uint16_t bpp;
	uint32_t data_size;
	uint8_t *data;
} bitmap_t;


// Custom.
int bitmap_get_monochrom(uint8_t *buffer, char const *path, size_t width, size_t heigh);

// Primitives
int bitmap_open(bitmap_t *bitmap, char const *path);
int bitmap_close(bitmap_t *bitmap);

#endif /*__BITMAP_H__*/
