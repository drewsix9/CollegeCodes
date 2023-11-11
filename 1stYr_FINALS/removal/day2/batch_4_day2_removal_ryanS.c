#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	/** ask for whole numbers with no 0 as first digit, add up all digits niya sa kada number, if total niya is prime -
	421 511 123 331 58
	7    7   6   7  13

	if one total prime number is the same as others remove the kaparehas.

	in this situation, remove 7.
	zero ra makapastop
	**/
	/**
	int n, num;
	int arr[n];

	do{
	scanf("%d", &num);
	if (num!=0)
	    arr[n]=num;
	    n++;
	} while (num!=0);
	**/

	int n=9;
	int array[] = {0,0,0,0,0,0,0,0,0};
	int arraySum[] = {0,0,0,0,0,0,0,0,0};
	int primeArray[]= {0,0,0,0,0,0,0,0,0};
	int orderedArray[] = {0,0,0,0,0,0,0,0,0};

	for (int i=0; i<n; i++) {
		int num;
		printf("Enter number: ");
		scanf("%d", &num);
		array[i] = num;
		int sum=0;

		if (num!=0) {
			for (int j=1; j<n; j++) {
				int rem = num%10;
				int div = num/10;
				sum=sum+rem;
				num=div;

			}
		} else {
			break;
		}

		arraySum[i] = sum;

	}
// printf("ArraySum: %d %d %d %d \n", arraySum[0], arraySum[1], arraySum[2], arraySum[3]);


// CHECKING IF PRIME NUMBER OR NOT PO HEHE
	/** if prime, ma apil siya. if dili siya prime, magpabilin. **/
	for (int k=0; k<n; k++) {
		int count=0;
		for (int l=2; l<arraySum[k]; l++) {
			if (arraySum[k]%l==0) {
				count++;
			}
		}
//	printf("Count for ArraySum[%d]: %d. \n", k, count);
		if (count==0) {
			primeArray[k] = arraySum[k];
		} else {
			orderedArray[k] = arraySum[k];
		}
	}


	/**printf("Ordered Array: %d \n", orderedArray[2]);
	printf("prime Array: %d \n", primeArray[0]);
	**/

	/** PRINTING THE COMPOSITE **/
	for(int p=0; p<n; p++) {
		if (orderedArray[p]!=0 ) {
			printf("%d \n", array[p]);

		}

		if(primeArray[p]!=primeArray[p+1] && primeArray[p]!=primeArray[p-1] && primeArray[p]!=primeArray[p+2] && primeArray[p]!=primeArray[p-2] && primeArray[p]!=primeArray[p+3] && primeArray[p]!=primeArray[p-3] && primeArray[p]!=primeArray[p+4] && primeArray[p]!=primeArray[p-4]) {
			if (primeArray[p]!=0 ) {
				printf("%d \n", array[p]);
			}
		}
	}
	return 0;
}
