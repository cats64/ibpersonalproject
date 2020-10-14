#include <stdint.h>
#include "tty.h"

void main(void) {
    term_init();
    // Newline support is still broken
    term_writesector("Hello, world!");
}
