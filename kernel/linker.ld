/* GNU compiler script. */

/* Start execution at... well, the start */
ENTRY(_start)

/* Tell GCC where to put things in the final kernel. */
SECTIONS
{
	/* GRUB expects to find us at the 1M mark, and we expect to find GRUB
	   below 1M. Let's load the kernel above that point. */
	. = 1M;

	/* But first let's put the multiboot header */
	.text BLOCK(4K) : ALIGN(4K)
	{
		*(.multiboot)
		*(.text)
	}
	
	/* The actual kernel */
	.rodata BLOCK(4K) : ALIGN(4K)
	{
		*(.rodata)
	}
	
	/* Read-write data */
	.data BLOCK(4K) : ALIGN(4K)
	{
		*(.data)
	}
	
	/* Read-write data and stack */
	.bss BLOCK(4K) : ALIGN (4K)
	{
		*(COMMON)
		*(.bss)
	}
	
	/* Despite all of this, GCC will add its own sections to the kernel.
	   This is not a bug; it is expected behavior. All is good. */
}	
