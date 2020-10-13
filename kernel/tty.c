#include "tty.h"
#include "vga.h"

/* We first define the size of the VGA text mode buffer, and where the data should be copied to. The static const keywords are used to ensure that these variables are:
 - Local to this file
 - Remain constant (Can't be changed during execution)
 This allows us to minimize memory usage, and the kernel's final size.*/
static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;

/* The use of pointers here is because this is an actual memory location */
static uint16_t* const VGA_MEMORY = (uint16_t*) 0xB8000;

/* The use of size_t is because these should never be extraneous */
static size_t term_row;
static size_t term_column;
static uint8_t term_color;
/* Will refer to the location 0xB8000 earlier */
static uint16_t* term_buffer;


