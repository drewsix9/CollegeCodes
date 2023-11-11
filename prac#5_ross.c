/*Write a C program that reads in a list of integers
from the user until the user enters 0, stores them in an array,
and then finds and prints out the second largest and second
smallest values in the array.*/

#include <stdio.h>
int main() {
	int num,n=0,arr[100];

	do {
		printf("Enter input %d: ",n);
		scanf("%d",&num);
		if(num!=0) {
			arr[n] = num;
			n++;
		}
	} while(num!=0);

	for(int i=0; i<n; i++) {
		for(int j=i+1; j<n; j++) {
			if(arr[i]>arr[j]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	printf("\nSecond Smallest: %d",arr[1]);
	printf("\nSecond Largest: %d",arr[n-2]);

	return 0;
}
