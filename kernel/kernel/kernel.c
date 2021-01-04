#include <stdio.h>
#include <string.h>
#include <kernel/tty.h>
#include <kernel/asm.h>
/* This kernel_main is called in the boot.S file.
 * Not a lot is done here- it's mostly delegated somewhere else. */
void kernel_main(void) {
    term_init();
    //int i = 125;
    //int d = 8;
    //char test[100] = "Hello ";
    //char test2[] = "World!";
    printf("================================================================================");
    printf("SimpleOS: created by Nathaniel Flores. SOME RIGHTS RESERVED 2020-2021\n\n");
    printf("Video Screen Information: 80x25, address at 0xB8000\n");
    printf("Display Mode: Text Mode (0x044A)\n");
    printf("Hard disk count: (not detected)\n");
    printf("Kernel mode: Protected (no paging)\n");
    printf("Arch: i386-elf\n");
    int x = 40;
    int y = 70;
    // Since pointers don't technically count as a real "type", we cast to void *
    printf("\nReading memory addresses of kernel variables y and x:\n0x%d 0x%d", (void *)&y, (void *)&x);
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
