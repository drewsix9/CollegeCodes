#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num, n = 0, arr[100], freq[100], count;

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

	for (int i = 0; i < 100; i++)
	{
		freq[i] = -1;
	}

	for (int i = 0; i < n; i++)
	{
		count = 1;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] == arr[j])
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

	for (int i = 0; i < n; i++)
	{
		if (freq[i] == 1)
		{
			printf("%d ", arr[i]);
		}
	}

	return 0;
}
