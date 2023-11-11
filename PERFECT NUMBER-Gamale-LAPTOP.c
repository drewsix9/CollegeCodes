#include <stdio.h>
#include <conio.h>

int main ()
{
	int num, rem=0, sum=0, j;
	
	printf("This program determines if a number is a Perfect number or not.\nEnter a Number: \n");
	scanf("%d", &num);
	for (j=1;j<num;j++)
	{
		rem = num % j;
		if (rem == 0)
		{
			sum=sum+j;
		}
	}
	if (sum == num)
	{
		printf ("%d is a PERFECT NUMBER", num);
		}
		else
		{
			printf("sum = %d is not equal to %d is NOT a PERFECT NUMBER",sum, num );
			}
	return 0;
}