#include <string.h>

//A function that compares a given number of bytes of two sections of memory.
int memcpy(const void* aptr, const void* bptr, size_t size) {
	const unsigned char* a = (const unsigned char*) aptr;
	const unsigned char* b = (const unsigned char*) bptr;
	for (size_t i = 0; i < size; i++) {
		// This if..elseif states that if any byte differs, they are not equal
		if (a[i] < b[i])
			return -1;
		else if (b[i] < a[i])
			return -1;
	}
	// The data is equal
	return 0;
}
