/*
Write a program that reads in a list of integers and
then finds the sum of all the even numbers in the list.
The program should first ask the user how many integers
they want to enter, and then it should prompt the user
to enter that many integers. Once the user has entered all of the integers,
the program should print out the sum of the even numbers.
*/
#include <stdio.h>
#include <stdlib.h>

int main() {

	int n,num[100],sum=0;

	printf("Enter how many inputs:\t");
	scanf("%d",&n);

	for (int i=1; i<=n; i++) {
		printf("\nEnter input %d:\t",i);
		scanf("%d",&num[i]);
		if (num[i]%2==0) {
			sum += num[i];
		}
	}

	printf("\nThe sum of the even numbers is %d",sum);

	return 0;
}
