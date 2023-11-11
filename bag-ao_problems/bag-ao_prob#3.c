#include <stdio.h>
#include <stdlib.h>

void ascending(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    // printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

void descending(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] < arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    // printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

void printPrime(int arr[], int size)
{
    // printf("\n");
    for (int i = 0; i < size; i++)
    {
        int factor = 0;
        for (int j = 2; j < arr[i]; j++)
        {
            if (arr[i] % j == 0)
            {
                factor++;
                break;
            }
        }
        if (factor == 0 && arr[i] != 1)
        {
            printf("%d ", arr[i]);
        }
    }
}

void printComp(int arr[], int size)
{
    // printf("\n");
    for (int i = 0; i < size; i++)
    {
        int factor = 0;
        for (int j = 2; j < arr[i]; j++)
        {
            if (arr[i] % j == 0)
            {
                factor++;
                break;
            }
        }
        if (factor > 0)
        {
            printf("%d ", arr[i]);
        }
    }
}

int main()
{
    int n, arr[100];
    printf("\nEnter no. of inputs: ");
    scanf("%d", &n);
    printf("\nEnter inputs: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\n[1] - ascending\n[2] - descending\n[3] - print prime only\n[4] - print comp only\n\nEnter options: ");

    int nn = 0, choice[100], num;

    do
    {
        scanf("%d", &num);
        if (num != 0)
        {
            choice[nn] = num;
            nn++;
        }
        else if (num < 1 && num > 4)
        {
            printf("\nWrong input!");
            nn = 0;
            break;
        }
    } while (num != 0);

    for (int i = 0; i < nn; i++)
    {
        if (choice[i] == 1)
        {
            printf("\nOutput [%d]: ", i + 1);
            ascending(arr, n);
        }
        else if (choice[i] == 2)
        {
            printf("\nOutput [%d]: ", i + 1);
            descending(arr, n);
        }
        else if (choice[i] == 3)
        {
            printf("\nOutput [%d]: ", i + 1);
            printPrime(arr, n);
        }
        else if (choice[i] == 4)
        {
            printf("\nOutput [%d]: ", i + 1);
            printComp(arr, n);
        }
    }
    return 0;
}