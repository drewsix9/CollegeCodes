#include <stdio.h>
#include <conio.h>



int main (void)
{
	int num, rem, factor, j;
	rem = 0;
	factor = 0;
	j = 2;
	
	printf("Enter a Number: \n");
	scanf("%d", &num);
	rem = num % j;
	printf("%d", rem);
	return 0;
}