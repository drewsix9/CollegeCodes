#include <stdio.h>
#include <conio.h>



int main (void) {
	int num, factor=0, j;

	printf("This program determines if a number is Prime or Composite.\nEnter a Number: \n");
	scanf("%d", &num);

	for (j=2; j<num; j++) {

		if (num%j == 0) {
			factor++;
			break;
		}
	}

	if (factor == 0) {

		printf("\n%d is a PRIME number\n", num);

	} else {

		printf("\n%d is a COMPOSITE number\n", num);
	}
	return 0;
}