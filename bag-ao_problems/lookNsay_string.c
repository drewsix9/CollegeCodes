#include <stdio.h>
#include <string.h>

#define MAX 1000

int main() {
  char str[] = "1211";
  char newstr[MAX] = {0};
  int n = strlen(str);
  int j = 0;

  printf("\n");

  for (int i = 0; i < n; i++) {
    int count = 1;
    char temp = str[i];

    while (str[i] == str[i + 1]) {
      count++;
      i++;
    }

    newstr[j] = count + '0';
    j++;
    newstr[j] = temp;
    j++;
  }

  for (int i = 0; i < j; i++) {
    printf("%c ", newstr[i]);
  }

  return 0;
}
