#include <stdio.h>
#include <stdlib.h>

int main() {
	int n=0,nn=0,factor,temp;
	float num,arr[100],prime[100];

	printf("Enter inputs: ");
	do {
		scanf("%f",&num);
		if(num!=0) {
			arr[n] = num;
			n++;
		}
	} while(num!=0);

	float cast;
	for(int i=0; i<n; i++) {
		cast = arr[i] - (int)arr[i];
		if(cast!=0) { // if it has decimal
			factor=0;
			temp = (int)arr[i];
			for(int j=2; j<temp; j++) { //check if prime
				if(temp % j == 0) {
					factor++;
					break;
				}
			}
			if(factor==0) { // if it is prime
				prime[nn] = arr[i];
				nn++;
			}
		}
	}

	// sorting
	float temp1;
	for(int i=0; i<nn; i++) {
		for(int j=i+1; j<nn; j++) {
			if(prime[i] > prime[j]) {
				temp1 = prime[i];
				prime[i] = prime[j];
				prime[j] = temp1;
			}
		}
	}

	printf("\nThe greatest prime decimal number is: %f",prime[nn-1]);

	return 0;
}
