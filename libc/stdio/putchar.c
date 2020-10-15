#include <stdio.h>

//TODO: find some way to build this for libk only
#include <kernel/tty.h>

int putchar(int ic) {
	char c = (char) ic;
	//TODO: add something that prints to the terminal
	//TODO: implement stdio and/or a write() syscall
	return ic;
}
