#include <stdio.h>
int checkprime(int);
int main() {
  int num1, num2, num3, num4, i, prim1, prim2, comp1, comp2, gprim, gcomp, lprim, lcomp, gcd, quot, rem, max, min;

  printf("Enter 4 numbers (2 primes, 2 composites) : ");
  scanf("%d %d %d %d", &num1, &num2, &num3, &num4);
  if (checkprime(num1) == 0) {
    prim1 = num1;
  } else {
    comp1 = num1;
  }
  if (checkprime(num2) == 0) {
    prim2 = num2;
  } else {
    comp2 = num2;
  }
  if (checkprime(num3) != 0) {
    comp1 = num3;
  } else {
    prim1 = num3;
  }
  if (checkprime(num4) != 0) {
    comp2 = num4;
  } else {
    prim2 = num4;
  }
  if (prim1 > prim2) {
    gprim = prim1;
    lprim = prim2;
  } else {
    gprim = prim2;
    lprim = prim1;
  }
  if (comp1 > comp2) {
    gcomp = comp1;
    lcomp = comp2;
  } else {
    gcomp = comp2;
    lcomp = comp1;
  }
  if (lprim > lcomp) {
    max = lprim;
    min = lcomp;
  } else {
    max = lcomp;
    min = lprim;
  }
  for (;;) {
    quot = max / min;
    rem = max % min;
    if (rem == 0) {
      gcd = min;
      break;
    }
    max = min;
    min = rem;
  }
  printf("The lcd is %d", (lcomp * lprim) / gcd);
  printf("\n");
  printf("The sum of %d/%d + %d/%d  is : %f", lprim, lcomp, gprim, gcomp, ((float)gprim / (float)gcomp) + ((float)lprim / (float)lcomp));
  return 0;
}
int checkprime(int num) {
  int i, count = 0;

  for (i = 2; i < num; i++) {
    if (num % i == 0) {
      count++;
      break;
    }
  }
  return count;
}