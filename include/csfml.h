#ifndef __MY_CSFML_H__
# define __MY_CSFML_H__ 1

#include <SFML/Graphics.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <SFML/System/Export.h>
#include <SFML/Window/VideoMode.h>
#include <SFML/Audio.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Graphics.h>

// Define off_t type properly
#include <features.h>
#include <bits/types.h>
#ifndef __off_t_defined
# ifndef __USE_FILE_OFFSET64
typedef __off_t off_t;
# else
typedef __off64_t off_t;
# endif
# define __off_t_defined
#endif

// Define ssize_t properly
#ifndef __ssize_t_defined
typedef __ssize_t ssize_t;
# define __ssize_t_defined
#endif

// Define Linux error (errno based).
/* No such file or directory */
#define ENOENT 2
/* Out of memory */
#define ENOMEM 12
/* Bad address */
#define EFAULT 14

// Define screen size informations.
//TODO: generate this dynamically.
#ifndef SCREEN_WIDTH
# define SCREEN_WIDTH 1920
#endif
#ifndef SCREEN_HEIGHT
# define SCREEN_HEIGHT 1080
#endif

// Define frame rate
#ifndef FRAME_RATE
# define FRAME_RATE 64
#endif

/*
    All macros below are here to re-define CSFML functions's name.
    (because original are too long).
*/
// sprite part.
#define sprite_set_pos sfSprite_setPosition
#define sprite_set_area sfSprite_setTextureRect
#define sprite_get_zone sfSprite_setTextureRect
#define sprite_create sfSprite_create
#define sprite_destroy sfSprite_destroy

// texture part.
#define texture_create sfTexture_create
#define texture_get_img sfTexture_createFromImage
#define texture_set_sprite sfSprite_setTexture
#define texture_destroy sfTexture_destroy

// window part.
#define wcreate sfRenderWindow_create
#define wdestroy sfRenderWindow_destroy
#define wclear sfRenderWindow_clear
#define wopen sfRenderWindow_isOpen
#define wclose sfRenderWindow_close
#define wdisplay sfRenderWindow_display
#define wdisplay_sprite sfRenderWindow_drawSprite
#define wpevent sfRenderWindow_pollEvent

// image part.
#define image_get sfImage_createFromFile

// key part.
#define kpressed sfKeyboard_isKeyPressed

// mouse part.
#define mouse_get_pos sfMouse_getPositionRenderWindow
#define mouse_pressed sfMouse_isButtonPressed

// clock sprite.
#define clock_get_time sfClock_getElapsedTime

// type part.
#define window_d sfRenderWindow
#define texture_d sfTexture
#define mode_d sfVideoMode
#define rect_d sfIntRect
#define event_d sfEvent
#define eclose_d sfEvtClosed
#define settings_d sfContextSettings

#endif /* __MY_CSFML_H__ */
