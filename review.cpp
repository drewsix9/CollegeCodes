#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char str[100] = "aaaaeeeeiiiioooouuuuu";
  char *ptr = strchr(str, 'e');
  int pos = ptr - str;
  printf("%c[%d]", str[pos], pos);
}