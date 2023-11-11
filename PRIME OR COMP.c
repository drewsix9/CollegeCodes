#include <stdio.h>
#include <conio.h>



int main (void) {
	int num, rem=0, factor=0, j;

	printf("This program determines if a number is Prime or Composite.\nEnter a Number: \n");
	scanf("%d", &num);
	for (j=2; j<num; j++) {
//		rem = num % j;
		if (num%j == 0) {
			factor++;
		}
	}
	if (factor == 0) {
		printf("\n%d is a PRIME number\n", num);
	} else {
		printf("\n%d is a COMPOSITE number\n", num);
	}
	return 0;
}