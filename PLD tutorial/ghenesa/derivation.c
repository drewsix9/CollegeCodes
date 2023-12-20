#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// not yet done

char *derive(char *str, int len) {
  char res[100][100];
  char *token = strtok(str, "+-");
  int n = 0;
  while (token) {
    printf("%s\n", token);
    token = strtok(NULL, "+-");
    strcpy(res[n++], token);
    NewFunction(str, token);
  }
}

void NewFunction(char *str, char *token) {
  // print the operator before token
  printf("%c ", str[token - str - 1]);
}
int main() {
  char str[100];
  printf("Enter expression to derive (d/dx): ");
  fgets(str, 100, stdin);
  int len = strlen(str);
  printf("%s", derive(str, len));
}