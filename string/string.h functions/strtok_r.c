#include <stdio.h>
#include <string.h>

int main() {
  char *str = strdup("Hello, world! This is a string.");
  // printf("Enter strings to parse: ");
  // scanf("%[^\n]s", str);

  char *token;
  char *remain = str;
  while ((token = strtok_r(remain, " ,!.", &remain))) {
    printf("%s\n", token);
  }
}