#include <string.h>

// A function that concatenates strings
char * strcat(char *dst, const char *src) {
	// This checks to see if the strings are big enough to fit
	return strcpy(dst + strlen(dst), src);
}
