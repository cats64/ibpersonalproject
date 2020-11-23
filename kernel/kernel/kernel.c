#include <stdio.h>
#include <kernel/tty.h>
/* This kernel_main is called in the boot.S file.
 * Not a lot is done here- it's mostly delegated somewhere else. */
void kernel_main(void) {
    term_init();
    int i = 125;
    int d = 8;
    printf("    ===- SimpleOS -===\nCopyright Nathaniel S. Flores. SOME RIGHTS RESERVED.\n");
    // We get base eight AND base ten!
    printf("\n\nInteger print test: %d %o", i, d);
    // Pointer printing works too!
    printf("\nPointer: i is 0x%p and d is 0x%p", (void *)&i, (void *)&d);
}
