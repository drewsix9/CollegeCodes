#include <stdio.h>
#include <stdlib.h>

int main()
{

	int num, k = 0, prime[100], factor;

	printf("Enter num to be prime factored: ");
	scanf("%d", &num);

	// determine all prime numbers and assign to an array
	for (int i = 2; i <= 100; i++)
	{
		factor = 0;
		for (int j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				factor++;
			}
		}
		if (factor == 0)
		{
			prime[k] = i;
			k++;
		}
	}

	printf("\nThe prime factor(s) of %d are: ", num);

	int quot, rem, h = 0, primefactors[100], l = 0;

	// determining prime factors
	for (;;)
	{
		quot = num / prime[l];
		rem = num % prime[l];
		if (rem == 0)
		{
			primefactors[h] = prime[l];
			h++;
			num = quot;
		}
		else
		{
			l++;
		}
		if (quot == 0)
		{
			break;
		}
	}

	// prints the prime factors of num
	for (int i = 0; i < h; i++)
	{
		printf("%d ", primefactors[i]);
	}

	return 0;
}
