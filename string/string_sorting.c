#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void string_sort_print(char arr[])
{
	int len = strlen(arr);

	for (int i = 0; i < len; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			if (arr[i] > arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	printf("\n");
	for (int i = 0; i < len; i++)
	{
		printf("%c", arr[i]);
	}
}

int main()
{

	char arr[] = "vndjak";

	string_sort_print(arr);

	return 0;
}
