#include <stdint.h>

/* What does this file do? It helps the kernel print text to the screen. 
   This is a wrapper over raw hardware. 
   
   See also: tty.h, libc/stdio.h */

/* Okay, so we start by defining colors in the graphics card. 
   This _should_ be a #define, but that would require so many entries. */
enum vga_color {
	COLOR_BLACK = 0,
	COLOR_BLUE = 1,
	COLOR_GREEN = 2,
	COLOR_CYAN = 3,
	COLOR_RED = 4,
	COLOR_MAGENTA = 5,
	COLOR_BROWN = 6,
	COLOR_LIGHT_GREY = 7,
	COLOR_DARK_GREY = 8,
	COLOR_LIGHT_BLUE = 9,
	COLOR_LIGHT_GREEN = 10,
	COLOR_LIGHT_CYAN = 11,
	COLOR_LIGHT_RED = 12,
	COLOR_LIGHT_MAGENTA = 13,
	COLOR_LIGHT_BROWN = 14,
	COLOR_WHITE = 15,
}

/* Now create a function that returns the color. 
   This allows dynamic color setting. 
   We can save space by using small valuesu. That's why we include stdint */
static inline uint8_t vga_print_color(enum vga_color fg, enum vga_color bg) {
	return fg | bg << 4;
}

/* So when we set color, the entry to VGA memory must have:
	-The first bit as foreground
	-The second bit as background
   As a result, this bitwise magic allows for some sweet colors. 
   Sadly there's not a ton of decent colors open to us. */

/* But what does this function do? Well, we give it a character...
   and it creates data that we can put into the VGA card! */ 
static inline uint16_t vga_entry(unsigned char uc, uint8_t color) {
	return (uint16_t) uc | (uint16_t) color << 8;
}
