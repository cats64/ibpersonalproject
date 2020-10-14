#include <string.h>

/* This function copies a string from one location to another. 
 * Part of the <string.h> family of functions. 
 * See the rest of the folder.*/
void* memcpy(void* dstptr, const void* srcptr, size_t size) {
    unsigned char* dst = (unsigned char*) dsptr;
    const unsigned char* src = (const unsigned char*) srcptr;
    for (size_t i = 0; i < size; i++)
        dst[i] = src[i];
    return dstptr;
} 
