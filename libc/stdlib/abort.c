#include <stdio.h>
#include <stdlib.h>

__attribute__((__noreturn__))
void abort(void) {
#if defined(__is_libk)
	printf("kernel panic: aborting\n");
#else
	//TODO: when we write multitasking, they should die; we need a syscall
	printf("abort() called, exiting\n");
#endif
	while (1) { }
	__builtin_unreachable();
}
