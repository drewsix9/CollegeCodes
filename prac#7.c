#include <stdio.h>
#include <stdlib.h>

/*Write a program that takes in an array of integers
and finds the second largest number in the array
using the sorting algorithm. Your program should then
print out the second largest number in the array.*/

int main() {

	int n,arr[100];

	printf("Enter how many inputs: ");
	scanf("%d",&n);

	//takes in the arrays
	for(int i=0; i<n; i++) {
		printf("Enter input %d: ",i+1);
		scanf("%d",&arr[i]);
	}

	for(int i=0; i<n; i++) {
		printf("array [%d] = %d\n",i,arr[i]);
	}

	//bubble sort
	int temp;
	for(int i=0; i<n; i++) {
		for(int j=i+1; j<n; j++) {
			if(arr[i]>arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	printf("\nSecond largest number is : %d",arr[n-2]);
	return 0;
}
