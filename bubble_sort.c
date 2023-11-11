// bubble sort
// increasing order

// index: 0 1 2 3 4 5 6
//  arr : 1,2,3,4,5,6,7

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int arr[] = {3, 6, 2, 5, 1, 7, 4};
	int length = sizeof(arr) / sizeof(arr[0]);
	printf("length = %d\n", length);

	for (int i = 0; i < length; i++)
	{
		printf("array %d: %d\n", i, arr[i]);
	}

	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	printf("\n\n");
	for (int i = 0; i < length; i++)
	{
		printf("array %d: %d\n", i, arr[i]);
	}

	return 0;
}
