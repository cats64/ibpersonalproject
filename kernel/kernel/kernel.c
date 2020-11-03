#include <stdio.h>
#include <kernel/tty.h>
/* This kernel_main is called in the boot.S file.
 * Not a lot is done here- it's mostly delegated somewhere else. */
void kernel_main(void) {
    term_init();
    // TODO: The tab still prints some weird character- fix that
    printf("\t===- SimpleOS -===\nCopyright Nathaniel S. Flores. ALL RIGHTS RESERVED.\n");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nInit finished.");
}
