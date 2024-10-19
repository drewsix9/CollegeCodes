#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char str[] = "1011.1";
  int size = strlen(str);
  int pos_point;

  for (int i = 0; i < size; i++) // find decimal point
  {
    if (str[i] == '.') {
      pos_point = i;
    }
  }

  int sum = 0, k = 0;
  for (int i = pos_point - 1; i >= 0; i--) {
    if (str[i] == '1') {
      sum = sum + pow(2, k);
      k++;
    } else {
      k++;
    }
  }

  int l = 2;
  float sum2 = 0, prod2 = 1, quot = 0;
  for (int i = pos_point + 1; i <= size - 1; i++) {
    if (str[i] == '1') {
      quot = 1.0 / l;
      sum2 += quot;
      l = l * 2;
    } else {
      l = l * 2;
    }
  }
  float result = sum + sum2;
  printf("\nResult = %f", result);
  return 0;
}
