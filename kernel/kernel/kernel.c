#include <stdio.h>
#include <string.h>
#include <kernel/tty.h>
#include <kernel/asm.h>
/* This kernel_main is called in the boot.S file.
 * Not a lot is done here- it's mostly delegated somewhere else. */
void kernel_main(void) {
    // Start the virtual terminal.
    term_init();
    // This is 80 characters and thus we don't need a newline- the virtual terminal will wrap the line for us.
    printf("================================================================================");
    printf("SimpleOS: created by Nathaniel Flores. SOME RIGHTS RESERVED 2020-2021\n\n");
    // This is given information.
    printf("Video Screen Information: 80x25, address at 0xB8000\n");
    printf("Display Mode: Text Mode (0x044A)\n");
    // TODO: fix farpeek so I can actually display this
    printf("Hard disk count: (not detected)\n");
    printf("Kernel mode: Protected (no paging)\n");
    printf("Arch: i386-elf\n");
    int x = 40;
    int y = 70;
    // Since pointers don't technically count as a real "type", we cast to void *
    printf("\nReading memory addresses of kernel variables y and x:\n0x%d 0x%d (Operation successful)", (void *)&y, (void *)&x);
    printf("\n\n\n\n\n\n\n\n\n\n\n================================================================================");
    // We get base eight AND base ten!
    //printf("\n\nInteger print test: %d %o", i, d);
    // Pointer printing works too!
    //printf("\nPointer: i is 0x%p and d is 0x%p", (void *)&i, (void *)&d);
    //printf("\nNew test:\n");
    //strcat(test, test2);
    // String concat!
    //puts(test);
}
