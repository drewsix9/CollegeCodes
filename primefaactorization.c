#include <stdio.h>
#include <stdlib.h>

/*Write a program that takes in an integer
and finds all of its prime factors.
The program should then store the prime factors
in an array and print out the array.*/

int main()
{
	int n, prime[100], num, factor, k = 0;

	printf("Enter how many inputs: ");
	scanf("%d", &n);

	// takes all prime numbers from 2-100
	for (int i = 2; i < 100; i++)
	{
		factor = 0;
		for (int j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				factor++;
				break;
			}
		}
		if (factor == 0)
		{
			prime[k] = i;
			k++;
		}
	}

	int arr[n];
	printf("Enter inputs: ");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	printf("\nOutput:\n");
	for (int i = 0; i < n; i++)
	{
		printf("%8d = ", arr[i]);

		int quot, rem, j = 0;

		for (;;)
		{
			quot = arr[i] / prime[j];
			rem = arr[i] % prime[j];
			if (rem == 0) // current prime number is divisible
			{
				printf("%d ", prime[j]);
				arr[i] = quot;
			}
			else // current prime number is NOT divisible
			{
				j++;
			}
			if (quot == 0)
			{
				break;
			}
		}
		printf("\n");
	}

	return 0;
}
