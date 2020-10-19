#include <limits.h>
#include <stdbool.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

// A function that checks to see if the string is legitimate and nonzero
static bool print(const char* data, size_t length) {
	const unsigned char* bytes = (const unsigned char*) data;
	// If the string is nonzero
	for(size_t i = 0; i < length; i++)
		if (putchar(bytes[i]) == EOF)
			return false;
	return true;
}

/* A function that prints a string, and replaces certain parts of the string with data.
 * This is easily the longest single function in this OS, and is commented very well.
 * Please read all of them to be sure you understand the function before calling it.
 * Warning: code is very ugly and hack-y. You have been warned.*/
int printf(const char* restrict format, ...) {
	// Write the parameter list we are given to memory.
	va_list parameters;
	va_start(parameters, format);

	int written = 0;

	// If the character is not a NULL, keep printing
	while (*format != '\0') {
		// Since while is a loop, count the amount of characters left to print.
		size_t maxrem = INT_MAX - written;

		// Check for a specifier (a character + %)
		if (format[0] != '%' || format[1] == '%') {
			if (format[0] == '%')
				format++;
			size_t amount = 1;
			while (format[amount] && format[amount] != '%')
				amount++;
			if (maxrem < amount) {
				//TODO: when we return from this, mark the error as overflow
				return -1;
			}
			if (!print(format, amount))
				return -1;
			format += amount;
			written += amount;
			continue;
		}

		/* Mark the format specifier in the list we start at.
		 * This will be useful when we loop the following section. */
		const char* format_begun_at = format++;

		// Is this format a character? If so, print it.
		if (*format == 'c') {
			// Increment the amount of formats we have seen.
			format++;
			// char is now int, this is a gross hack
			char c = (char) va_arg(parameters, int);
			if (!maxrem) {
				//TODO: when we return from this, mark the error as overflow
				return -1;
			}
			if (!print(&c, sizeof(c)))
				return -1;
			written++;
		// Is this format a string? If so, print the whole thing.
		} else if (*format == 's') {
			// Increment the amount of formats we have seen.
			format++;
			const char* str = va_arg(parameters, const char*);
			size_t len = strlen(str);
			if (maxrem < len) {
				//TODO: when we return from this, mark the error as overflow
				return -1;
			}
			if (!print(str, len))
				return -1;
			written += len;
		} else {
			// Do not increment- we haven't seen a specifier.
			format = format_begun_at;
			size_t len = strlen(format);
			if (maxrem < len) {
				//TODO: when we return from this, mark the error as overflow
				return -1;
			}
			if (!print(format, len))
				return -1;
			written += len;
			format += len;
		}
	}

	// Clean up the list of parameters
	va_end(parameters);
	// Tell the caller how many characters we printed
	return written;
}
