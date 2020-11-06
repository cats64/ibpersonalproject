#include <stdint.c>
#include <stddef.h>

#include <kernel/asm.h>

/* This file allows us to mess with memory in ways not normally avalible to us in the C language by itself. You _will_ need GCC for this, no other compiler does GNU extensions */

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
  asm volatile ( "outb %0, %1"
		 : "a"(val)
		 : "Nd"(port) );
}

/* I'd like to write a farpeek and farpoke as well for reading and messing with memory locations, but for now, this will be good. The reason for not writing them is I need to be able to restore register state after changing memory locations in assembly, so I don't critically damage anything. */
