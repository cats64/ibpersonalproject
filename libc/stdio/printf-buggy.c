#include <string.h>
#include <stdarg.h>
#include <stdio.h>

char * itoa(int, char *, int);

int printf(char * str, ...) {
  va_list vl;
  int i = 0, j = 0;
  char buff[100]={0}, tmp[20];
  va_start(vl, str);
  while (str && str[i]) {
    if(str[i] == '%') {
      i++;
      switch(str[i]) {
      case 'c' : {
	buff[j] = (char)va_arg(vl,int);
	j++;
	break;
      }
      case 'd' : {
	itoa(va_arg(vl,int),tmp,10);
	memcpy(&buff[j],tmp,strlen(&buff));
	j += strlen(tmp);
	break;
      }
      case 'x': {
	itoa(va_arg(vl,int),tmp,16);
	memcpy(&buff[j],tmp,strlen(&buff));
	j += strlen(tmp);
	break;
      }
      }
    } else {
    buff[j] = str[i];
    j++;
    }
  }
  int c;
  for(c = 0; (c = strlen(&buff)); c++) {
    putchar(buff[c]);
  } 
  va_end(vl);
  return j;
}

char * itoa(int v, char * str, int b) {
  char * rc;
  char * ptr;
  char * low;

  if (b < 2 || b > 36) {
    *str = '\0';
    return str;
  }
  rc = ptr = str;
  if (v < 0 && b == 10) {
    *ptr++ = '-';
  }
  low = ptr;
  do {
    *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqestuvwxyz"[35 + v % b];
    v /= b;
  } while (v);
  *ptr-- = '\0';
  while (low < ptr) {
    char tmp = *low;
    *low++ = *ptr;
    *ptr-- = tmp;
  }
  return rc;
}
