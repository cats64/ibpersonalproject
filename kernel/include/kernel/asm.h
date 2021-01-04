#include <stdint.h>
#include <stddef.h>

/* You _will_ need GCC for this, no other compiler does GNU extensions */

// inb: a function for getting data from an I/O location or port
static inline uint8_t inb(uint16_t port) {
  uint8_t ret;
  // The assembly instruction is run, with the values being replaced with the function's info.
  asm volatile ( "inb %1, %0"
		 : "=a"(ret)
		 : "Nd"(port) );
  return ret;
}

// outb: a function for sending data on an I/O location or port
static inline void outb(uint16_t port, uint8_t val) {
	asm volatile ( "outb %0, %1" : : "a"(val), "Nd"(port) );
}

// farpeek: read a given memory address
static inline uint32_t farpeek(uint16_t sel, void* off) {
	uint32_t ret;
	asm ( "push %%fs\n\t"
	      "mov  %1, %%fs\n\t"
	      "mov  %%fs:(%2), %0\n\t"
	      "pop  %%fs"
	      : "=r"(ret) : "g"(sel), "r"(off) );
	return ret;
}

// farpoke: write a value to a given memory address
