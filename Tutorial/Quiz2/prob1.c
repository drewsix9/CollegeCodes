#include <stdio.h>

void MaxValue(int arr[], int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    printf("%d ", max);
}

void printPrime(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] != 1)
        {
            int count = 0;
            for (int j = 2; j < arr[i]; j++)
            {
                if (arr[i] % j == 0)
                {
                    count++;
                    break;
                }
            }
            if (count == 0)
            {
                printf("%d ", arr[i]);
            }
        }
    }
}

int main()
{
    int arr[100], n = 0, temp;
    printf("Enter inputs (0 to stop): ");

    while (scanf("%d", &temp) == 1 && temp != 0)
    {
        arr[n++] = temp;
    }

    printf("\nMax Value: ");
    MaxValue(arr, n);

    printf("\nPrime: ");
    printPrime(arr, n);

    return 0;
}