#ifndef _STDIO_H
#define _STDIO_H

#include <sys/cdefs.h>
// Every operating system follows this standard and so should we
#define EOF (-1)

#ifdef __cplusplus
extern "C" {
#endif

// Function prototypes for putchar.c
int printf(const char* __restrict, ...);
int putchar(int);
int puts(const char*);

#ifdef __cplusplus
}
#endif

#endif
