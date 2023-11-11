#include <stdio.h>
#include <stdlib.h>

/*Write a C program that reads in 10 integers from the user,
stores them in an array, and then prints out the largest and
smallest values in the array.*/

int main() {

	int arr[100],max,min;

	printf("Enter 10 integers: ");

	printf("\n\n");

	for(int i=0; i<10; i++) {
		printf("Enter integer %d: ",i+1);
		scanf("%d",&arr[i]);
	}

	max=arr[0];
	min=arr[0];
	for(int i=0; i<10-1; i++) {
		if(max<arr[i+1]) {
			max = arr[i+1];
		}
		if(min>arr[i+1]) {
			min=arr[i+1];
		}
	}

	printf("\nMaximum Value = %d",max);
	printf("\nMinumum Value = %d",min);


	return 0;
}
