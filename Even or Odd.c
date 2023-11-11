#include <stdio.h>
#include <conio.h>



int main (void)
{
	int num, rem;
	printf("Enter number:\t");
	scanf("%d", &num);
	rem = num % 2;
	if (rem == 0)
	{
		printf("\nEVEN\n");
	}
	else 
		{
			printf("\nODD\n");
			}
	return 0;
}