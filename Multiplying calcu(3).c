#include <stdio.h>

int main ()
{
	int multiplicand, multiplier, product;
	
	printf("Enter numbers to multiply: ");
	scanf("%d %d", &multiplicand, &multiplier);
	
	product = multiplicand * multiplier;
	
	printf("Your product of %d * %d = %d", multiplicand, multiplier, product);
	
	return 0;
}