#include <stdio.h>
#include <stdlib.h>

//TODO: this function never returns. There should be some way to optimize this further.
void abort(void) {
#if defined(__is_libk)
	printf("kernel panic: aborting\n");
#else	
	//TODO: when we write multitasking, they should die; we need a syscall
	printf("abort() called, exiting\n");
#endif
}
