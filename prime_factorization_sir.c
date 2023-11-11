#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	int i, j, k = 0, l = 0, a = 0, count, quot, num;
	int rem, prime[100], primefactor[100];
	printf("Enter a number:");
	scanf("%d", &num);
	for (i = 2; i <= 100; i++)
	{ // find for the prime numbers between 2 - 100
		count = 0;
		for (j = 2; j < i; j++)
		{
			if (count == 0)
			{
				prime[k] = i;
				k++;
			}
		}
		printf("The prime factor(s) of %d are: ", num);
		// Determine the prime factors
		for (;;)
		{
			quot = num / prime[l];
			rem = num % prime[l];
			if (rem == 0)
			{
				primefactor[a] = prime[l];
				a++;
			}
			else
			{
				l++;
			}
			num = quot;
			if (quot == 0)
			{
				break;
			}
			for (i = 0; i < a; i++)
			{
				printf("%d ", primefactor[i]);
			}
		}
		return 0;
	}
}
