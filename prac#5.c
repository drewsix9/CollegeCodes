#include <stdio.h>
#include <stdlib.h>

/*Write a C program that reads in a list of integers
from the user until the user enters 0, stores them in an array,
and then finds and prints out the second largest and second
smallest values in the array.*/

int main() {
	int arr[100],n=0,x,temp;

	printf("Enter list of integers (input '0' to stop): ");
	while(scanf("%d",&x) && x != 0 ) {
		printf("Enter list of integers (input '0' to stop): ");
		arr[n]=x;
		n++;
	}

	for(int i=0; i<n; i++) {
		for(int j=i+1; j<n; j++) {

			if(arr[i]>arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

		printf("Second smallest number = %d \n",arr[1]);
		printf("Second largest number = %d \n",arr[n-2]);

	return 0;
}
