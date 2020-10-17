/* crtn.s for x86 processors.
 * Part of the global constructor series. */
.section .init
	/* GCC will put the contents of crtend.o's .init here.
	 * The following is the only part we have to provide: */
	popl %ebp
	ret
.section .fini
	/* GCC will put the contents of crtend.o's .fini here.
	 * The following is the only part we have to provide: */
	popl %ebp
	ret
