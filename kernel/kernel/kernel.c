#include <stdio.h>
#include <string.h>
#include <kernel/tty.h>
#include <kernel/asm.h>
/* This kernel_main is called in the boot.S file.
 * Not a lot is done here- it's mostly delegated somewhere else. */
void kernel_main(void) {
    term_init();
    int i = 125;
    int d = 8;
    char test[100] = "Hello ";
    char test2[] = "World!";
    printf("    ===- SimpleOS -===\nCopyright Nathaniel S. Flores. SOME RIGHTS RESERVED.\n");
    // We get base eight AND base ten!
    printf("\n\nInteger print test: %d %o", i, d);
    // Pointer printing works too!
    printf("\nPointer: i is 0x%p and d is 0x%p", (void *)&i, (void *)&d);
    printf("\nNew test:\n");
    strcat(test, test2);
    // String concat!
    puts(test);
}
