#include <stdio.h>

int main() {
  while (1) {
    int h, m, s;
    printf("\n\nEnter hours: ");
    scanf("%d", &h);
    printf("\nEnter minutes: ");
    scanf("%d", &m);
    printf("\nEnter seconds: ");
    scanf("%d", &s);

    int total = (h * 60) + m + (s / 60);
    printf("\nOutput: %d", total);
  }
}