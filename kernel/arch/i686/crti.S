/* crti.s for x86 processors.
 * Part of the global constructor series. */
.section .init
.global _init
.type _init, @function
_init:
	push %ebp
	movl %esp, %ebp
	/* GCC will put crtbegin.o's .init here.
	 * This is the only part we need to provide. */
.section .fini
.global _fini
.type _fini, @function
_fini:
	push %ebp
	movl %esp, %ebp
	/* GCC will put crtbegin.o's .fini here.
	 * This is the only part we need to provide. */
