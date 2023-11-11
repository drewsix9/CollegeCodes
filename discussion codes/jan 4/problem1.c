#include <stdio.h>
#include <stdlib.h>

int main() {

	int num[100], composite[100],n,count,k=0,factorial=1;

	printf("Enter how many numbers: ");
	scanf("%d",&n);

	printf("Enter numbers:\n");

	for (int i=0; i<n; i++) {
		scanf("%d",&num[i]);
	}

	for (int i=0; i<n; i++) { //determines if composite
		count = 0;
		for (int j=2; j<num[i]; j++) {
			if(num[i]%j==0) {
				count++;
			}
		}
		if(count!=0) {
			composite[k] = num[i];
			k++;
		}
	}

	// determines the smallest of the composites in an array
	int min = composite[0];
	for (int i=1; i<k; i++) {
		if (composite[i]<min) {
			min = composite[i];
		}
	}

	//factorial of the smallest composite
	for (int j=2; j<=min; j++) {
		factorial = factorial * j;
	}

	printf("Smallest comp = %d\nFactorial = %d",min,factorial);

	return 0;
}
