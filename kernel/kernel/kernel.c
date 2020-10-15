#include <stdio.h>
#include <kernel/tty.h>
/* This kernel_main is called in the boot.S file.
 * Not a lot is done here- it's mostly delegated somewhere else.
 */
void kernel_main(void) {
    term_init();
    // Newline support is still broken
    printf("Print to screen test?\n");
}
