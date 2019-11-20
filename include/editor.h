#ifndef __EDITOR_H__
# define __EDITOR_H__

#include <stddef.h>
#include <stdint.h>
#include "bitmap.h"

extern void editor_entry(bitmap_t *bitmap, char const *path);
extern void editor_render(void);
extern void editor_event(void);

#endif /*__EDITOR_H__*/
