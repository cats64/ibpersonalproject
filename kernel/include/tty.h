#include <stddef.h>
/* What does this file do? Well, this file wraps some functions we need.
   You see, when we call printf(), how does printf() create a new line?
   This function creates an abstraction over hardware of the screen. 
   
   See also: libc/stdio.h, tty.c */

/* Also, we use the funky green on black color for normal text.
   We use gray on blue for kernel messages, like the BSOD of old. */

void term_init(void);
void term_putdown(char c);
void term_write(const char* data, size_t size);
void term_writesector(const char* data);
