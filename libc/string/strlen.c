#include <string.h>

/* This function returns the length of the string. */
size_t strlen(const char* str) {
    size_t len = 0;
    /* For every character in the string, increment the count by one */
    while (str[len])
        len++;
    return len;
}
