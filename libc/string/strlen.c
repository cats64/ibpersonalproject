#include <string.h>

/* This function returns the length of the string. 
 * Part of the <string.h> family of functions. 
 * See the rest of the folder.*/
size_t strlen(const char* str) {
    size_t len = 0;
    /* For every character in the string, increment the count by one */
    while (str[len])
        len++;
    /* Then give back the result */
    return len;
}
