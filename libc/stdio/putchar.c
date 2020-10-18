#include <stdio.h>

#if defined(__is_libk)
#include <kernel/tty.h>
#endif

int putchar(int ic) {
#if defined(__is_libk)
	char c = (char) ic;
	term_write(&c, sizeof(c));
#else
	//TODO: make a safe way of doing this from userspace
#endif
	return ic;
}
