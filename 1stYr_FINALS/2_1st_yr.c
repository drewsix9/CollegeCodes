#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	float arr[100], cast;

	printf("Enter number of inputs: ");
	scanf("%d", &n);

	printf("\nEnter input(s): ");
	for (int i = 0; i < n; i++)
	{
		scanf("%f", &arr[i]);
	}

	int temp;
	for (int i = 0; i < n; i++)
	{
		cast = arr[i] - (int)arr[i];
		if (cast == 0)
		{
			for (int j = i + 1; j < n; j++)
			{
				cast = arr[j] - (int)arr[j];
				if (cast == 0)
				{
					if (arr[i] > arr[j])
					{
						temp = arr[i];
						arr[i] = arr[j];
						arr[j] = temp;
					}
				}
			}
		}
	}

	printf("\nOutput:         ");
	for (int i = 0; i < n; i++)
	{
		if ((cast = arr[i] - (int)arr[i]) == 0)
		{
			printf("%.0f ", arr[i]);
		}
		else
		{
			printf("%.1f ", arr[i]);
		}
	}

	//	printf("\nOutput: ");
	//	for(int i=0; i<n; i++) {
	//		printf("%f ",arr[i]);
	//	}

	return 0;
}
