#ifndef _STRING_H
#define _STRING_H 1

#include <sys/cdefs.h>

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

// Function prototypes for memcpy.c and strlen.c
void* memcpy(void* __restrict, const void* __restrict, size_t);
size_t strlen(const char*);

#ifdef __cplusplus
}
#endif

#endif
