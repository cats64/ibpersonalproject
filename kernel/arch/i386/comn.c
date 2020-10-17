#include <stdint.h>
#include <stddef.h>

#include <kernel/comn.h>

// TODO: I'm unsure if static inline was a good choice

// A function that sends a value on an I/O port.
static inline void outb(uint16_t port, uint8_t val) {
	asm volatile ( "outb %0, %1" 
		       : "a"(val) 
		       : "Nd"(port) );
}

// A function that reads a value on an I/O port.
static inline uint8_t inb(uint16_t port) {
	uint8_t ret;
	asm volatile ( "inb %1, %0"
		       : "=a"(ret)
		       : "Nd"(port) );
	return ret;
}

//TODO: add a poke() and peek() function to read regular memory
