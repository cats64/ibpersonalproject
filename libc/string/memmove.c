#include <string.h>

// A function to move a given number of bytes to another location.
void* memmove(void* dstptr, const void* srcptr, size_t size) {
	unsigned char* dst = (unsigned char*) dstptr;
	const unsigned char* src = (const unsigned char*) srcptr;
	// If the destination is smaller than the size, then...
	if (dst < src) {
		// Copy every byte to the destination
		for (size_t i = 0; i < size; i++)
			dst[i] = src[i];
	// Otherwise, start with the size value, then...
	} else {
		// Copy only the amount of bytes given with size.
		for (size_t i = size; i != 0; i--)
			dst[i-1] = src[i-1];
	}
	return dstptr;
}
