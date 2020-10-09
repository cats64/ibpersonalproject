# Basic boot header. 

# Multiboot header.
.set ALIGN,	1<<0		 # align loaded modules on page boundaries
.set MEMINFO,	1<<1		 # give us a memory map, please
.set FLAGS,	ALIGN | MEMINFO  # the part that tells GRUB what we want
.set MAGIC,	0x1BADB002	 # number BADBOO for compliance
.set CHECKSUM,	-(MAGIC + FLAGS) # checksum to prove multibootness

# Actually add the header.
.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

# Reserve a stack for the kernel. 
# We're the only thing running, so it only needs to be 16Kib
.section .bss
.align 16
stack_bottom:
.skip 16384 
stack_top:

# Put in the kernel.
.section .text
.global _start
.type _start, @function
_start
	movl $stack_top, %esp
	
	# TODO: create our own GDT table
	
	# Call global constructors in CPUland
	call _init
	
	# Transfer control to our kernel. 
	# With this, we now have full control of the computer. 
	call kernel_main

	# If the kernel crashes for some reason, half the CPU to prevent damage.
	cli
1:	hlt
	jmp 1b
.size _start, . - _start
