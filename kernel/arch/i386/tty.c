#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <kernel/tty.h>

#include "vga.h"

/* We first define the size of the VGA text mode buffer, and where the data should be copied to. The static const keywords are used to ensure that these variables are:
 * - Local to this file
 * - Remain constant (Can't be changed during execution)
 * This allows us to minimize memory usage, and the kernel's final size. */
static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;

// The use of pointers here is because this is an actual memory location
static uint16_t* const VGA_MEMORY = (uint16_t*) 0xB8000;

// The use of size_t is because these should never be extraneous
static size_t term_row;
static size_t term_column;
static uint8_t term_color;
// Will refer to the location 0xB8000 earlier
static uint16_t* term_buffer;

/* All functions are void, because they don't need return values.
 * There's no way to ask the VGA card if something has printed to the screen- it just does it.
 * If it does work, I would have added return values.
 * Additionally, most functions here wrap other functions. */

// A function that starts the terminal by printing one blank space
void term_init(void) {
    term_row = 0;
    term_column = 0;
    term_color = vga_entry_color(VGA_COLOR_WHITE, VGA_COLOR_BLUE);
    term_buffer = VGA_MEMORY;
    for (size_t length = 0; length < VGA_HEIGHT; length++) {
        for (size_t width = 0; width < VGA_WIDTH; width++) {
            // This function creates an array, where the size of the array is the number of open character slots onscreen. 
            const size_t index = length * VGA_WIDTH + width;
            term_buffer[index] = vga_entry(' ', term_color);
        }
    }
}

// A function that allows the setting of color.
void term_setcolor(uint8_t color) {
    term_color = color;
}

// A function that is called by putchar() to place characters onscreen.
void term_putentryat(unsigned char c, uint8_t color, size_t width, size_t length) {
    // The use of an unsigned char is because of VGA hardware behavior.
    const size_t index = length * VGA_WIDTH + width;
    term_buffer[index] = vga_entry(c, color);
}

// A function that is used by putchar() for raw printing.
void term_putchar(char c) {
    unsigned char uc = c;
    term_putentryat(uc, term_color, term_column, term_row);
    // Should we hit the end of the buffer, wrap around
    if (++term_column == VGA_WIDTH) {
        term_column = 0;
        if (++term_row == VGA_HEIGHT) {
            term_row = 0;
        }
    }
}

// A function that writes whole chunks of data to the screen.
void term_write(const char* data, size_t size) {
    // Pointers are used for data to save on space
    for (size_t i = 0; i < size; i++)
        term_putchar(data[i]);
}

// A function that can write whole strings by passing the string and the size of the string.
void term_writesector(const char* data) {
    term_write(data, strlen(data));
}
