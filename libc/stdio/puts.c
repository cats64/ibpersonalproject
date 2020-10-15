#include <stdio.h>
/* Why is this just a printf() wrapper?
 * It's because puts() prints the line and adds a newline.
 * Thus, we can easily write our own puts(). */

int puts(const char* string) {
	return printf("%s\n", string);
}
