#include <stdio.h>
#include <stdlib.h>

/*Write a program that takes in an array of integers and calculates the
mean (average) of the numbers in the array. Your program should then
print out the mean of the numbers in the array.*/


int main() {

	int n,arr[100],sum;

	printf("Enter how many inputs: ");
	scanf("%d",&n);

	for(int i=0; i<n; i++) {
		printf("\nEnter input %d: ",i+1);
		scanf("%d",&arr[i]);
		sum+=arr[i];
	}

//	for(int i=0; i<n; i++) {
//		printf("array[%d] = %d\n",i,arr[i]);
//	}

	printf("\nAverage = %d",sum/n);


	return 0;
}
