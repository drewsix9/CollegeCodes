#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPrime(int num);

int main()
{
	int num, n, arr[100], freq[100], count;

	printf("Enter inputs: ");
	do
	{
		scanf("%d", &num);
		if (num != 0)
		{
			arr[n] = num;
			n++;
		}
	} while (num != 0);

	// initializing all freq[] to -1
	for (int i = 0; i < n; i++)
	{
		freq[i] = -1;
	}

	// find the freq of repeating prime numbers
	for (int i = 0; i < n; i++)
	{
		count = 1;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] == arr[j] && isPrime(arr[i]))
			{
				count++;
				freq[j] = 0;
			}
		}
		if (freq[i] != 0)
		{
			freq[i] = count;
		}
	}

	printf("\nArray after removing: ");
	for (int i = 0; i < n; i++)
	{
		if (freq[i] == 1)
		{
			printf("%d ", arr[i]);
		}
	}

	return 0;
}

// boolean function of isPrime
bool isPrime(int num)
{
	int factor = 0;

	for (int i = 2; i < num; i++)
	{
		if (num % i == 0)
		{
			factor++;
			break;
		}
	}
	if (factor == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
