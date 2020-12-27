#include <string.h>

// A function to copy one string to another.
char * strcpy(char *dst, const char *src) {
	char *tmp = dst;
	/* Copy the string, but make sure that it should be long enough
	to contain the other string and a null character */
	while ((*tmp ++ = *src ++) != '\0')
	// Nothing
	;
	return dst;
}
