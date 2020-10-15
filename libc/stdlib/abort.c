#include <stdio.h>
#include <stdlib.h>

//TODO: this function never returns. There should be some way to optimize this further.
void abort(void) {
	//TODO: we should make this only appear in the kernel's libc
	printf("kernel: panic: abort()\n");
	//TODO: when we write multitasking, they should die; we need a syscall
	printf("abort() called, exiting\n");
}
