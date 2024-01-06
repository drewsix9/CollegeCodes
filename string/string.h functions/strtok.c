// You are given a string containing a list of words separated by one or more spaces, tabs, or newline characters. Your task is to tokenize the string and count the number of words in it. You should use the strtok() function to achieve this.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 100

int main() {
  char buffer[BUFFER_SIZE];
  fgets(buffer, BUFFER_SIZE, stdin);
  char *str = malloc(strlen(buffer) + 1);
  strcpy(str, buffer);

  const char *const_str = str;

  char delim[] = " \t\n";           // delimiters are: space, tab, and new line.
  char *token = strtok(str, delim); // declare strtok outside the loop
  int count = 0;

  while (token != NULL) {
    count++;
    printf("%s\n", token);
    printf("index = %llu\n", token - const_str);
    token = strtok(NULL, delim); // NULL means to tokenize what was tokenize before
    printf("\n");
  }

  printf("\nsentence has %d words", count);

  return 0;
}