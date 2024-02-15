#include <stdio.h>

void printMinValue(int arr[], int size)
{
    int min = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    printf("%d", min);
}

void printComposite(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 2; j < arr[i]; j++)
        {
            if (arr[i] % j == 0)
            {
                printf("%d ", arr[i]);
                break;
            }
        }
    }
}

int main()
{
    int arr[100], temp, n = 0;
    printf("Enter inputs (0 to stop): ");

    while (scanf("%d", &temp) == 1 && temp != 0)
    {
        arr[n++] = temp;
    }

    printf("\nMinimum Value: ");
    printMinValue(arr, n);

    printf("\nComposite: ");
    printComposite(arr, n);

    return 0;
}