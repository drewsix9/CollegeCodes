#include <stdio.h>

int main()
{

    int colsize[100], num, arr[100][100];
    for (int i = 0; i < 2; i++)
    {
        int j = 0;
        printf("Enter array %d: ", i + 1);
        do
        {
            scanf("%d", &num);
            if (num != 0)
            {
                arr[i][j++] = num;
            }
        } while (num != 0);
        colsize[i] = j;
    }

    int arr2[100], n = 0;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < colsize[i]; j++)
        {
            arr2[n++] = arr[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr2[i] > arr2[j])
            {
                int temp = arr2[i];
                arr2[i] = arr2[j];
                arr2[j] = temp;
            }
        }
    }

    printf("\nOutput: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr2[i]);
    }

    return 0;
}