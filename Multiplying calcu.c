#include <stdio.h>

int main ()
{
	int multiplicand, multiplier, product;
	
	printf("Enter a multiplier: ");
	scanf("%d", &multiplicand);
	printf("\nEnter a multiplier: ");
	scanf("%d", &multiplier);
	product = multiplicand * multiplier;
	printf("\nYour product of %d * %d =\n", multiplicand, multiplier);
	printf("\n\n\n\n\n                  %d \n\n\n\n\n", product);
	return 0;
}