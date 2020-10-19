#include <string.h>

/* This function copies a string from one location to another. 
 * Part of the <string.h> family of functions. 
 * See the rest of the folder.*/
void* memcpy(void* restrict dstptr, const void* restrict srcptr, size_t size) {
    /* First create local variables of the arguments */
    unsigned char* dst = (unsigned char*) dstptr;
    const unsigned char* src = (const unsigned char*) srcptr;
    /* Make sure that we only copy the number of bytes we are told to */
    for (size_t i = 0; i < size; i++)
        dst[i] = src[i];
    return dstptr;
} 
