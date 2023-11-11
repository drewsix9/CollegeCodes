/*
Write a program that takes in a list of integers from the user
and then finds the maximum and minimum values in the list.
The program should first ask the user how many integers they want to enter,
and then it should prompt the user to enter that many integers.
Once the user has entered all of the integers,
the program should print out the maximum and minimum values.
*/
#include <stdio.h>
#include <stdlib.h>

int main() {

	int n;
	int num[100];
	int max=0,min=0;

	// Get the number of integers from the user
	printf("Enter how many inputs:\t");
	scanf("%d",&n);

	// Read in the integers
	for (int i=1; i<=n; i++) {
		printf("\nEnter input %d:\t",i);
		scanf("%d",&num[i]);
	}
	
	// Initialize the max and min values to the first integer in the array
	max=num[1];
	min=num[1];

	// Loop through the array and find the max and min values
	for (int i=1; i<=n; i++) {
		if (num[i]>max) {
			max = num[i];
		}
		if (num[i]<min) {
			min = num[i];
		}
	}

	for (int i=1; i<=n; i++) {
		printf("\nArray %d : %d\n",i,num[i]);
	}

	printf("\nThe Maximum Value is: %d",max);
	printf("\nThe Minimum Value is: %d",min);


	return 0;
}
