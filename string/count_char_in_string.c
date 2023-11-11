#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  char arr[] = "racecar";
  int count = 0;
  int i = 0;
  while (arr[i]) {
    count++;
    i++;
  }
  printf("Count = %d ", i);

  return 0;
}
