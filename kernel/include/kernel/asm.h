#ifndef _KERNEL_ASM_H
#define _KERNEL_ASM_H

#include <stdint.h>
#include <stddef.h>

// Function prototypes for asm.c
static inline uint8_t inb(uint16_t);
static inline void outb(uint16_t, uint8_t);

#endif

