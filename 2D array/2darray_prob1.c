#include <stdio.h>
#include <stdlib.h>

//user inputs no. of rows
//user inputs elements (until user inputs 0)
//arranges the whole array in ascending

void Ascending(int *arr, int n)
{
	for(int i=0; i<n; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			if(arr[i] > arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int main()
{

	int rows, rowsize[100],arr[100][100], num;

	printf("Enter number of arrays: ");
	scanf("%d", &rows);

	int j;
	for(int i=0; i<rows; i++)
	{
		j=0;
		printf("Enter array %d: ",i+1);
		do
		{
			scanf("%d", &num);
			if(num !=0)
			{
				arr[i][j++] = num;
			}
			rowsize[i] = j;
		}
		while(num!=0);
	}

	int newarr[100], n;
	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<rowsize[i]; j++)
		{
			newarr[n++] = arr[i][j];
		}
	}

	Ascending(newarr, n);

	for(int i=0; i<n; i++)
	{
		printf("%d ", newarr[i]);
	}
	return 0;
}
