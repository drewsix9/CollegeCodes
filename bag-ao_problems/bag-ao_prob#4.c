#include <stdlib.h>
#include <stdio.h>

void printPrime(int arr[], int n)
{
    for (int i = 0; i < n; i++)
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
        if (factor == 0)
        {
            printf("%d ", arr[i]);
        }
    }
}

void printComp(int arr[], int n)
{
    for (int i = 0; i < n; i++)
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

void ascending(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

void descending(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int n, choice1, choice2;
    printf("Enter no. of inputs: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter input(s): ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\n[1] - Choice 1:\n     [A] Only Prime\n     [B] Only Composite\n");
    printf("\n[2] - Choice 2:\n     [A] Arrange Ascending\n     [B] Arrange Descending\n\nEnter Choice: ");
    scanf("%d", &choice1);
    if (choice1 == 1)
    {
        system("cls");
        printf("\n[1] A. Only Prime\n[2] B. Only Composite\n\nEnter Choice: ");
        scanf("%d", &choice2);
        if (choice2 == 1)
        {
            printf("\nOutput: ");
            printPrime(arr, n);
        }
        else if (choice2 == 2)
        {
            printf("\nOutput: ");
            printComp(arr, n);
        }
    }
    else if (choice1 == 2)
    {
        system("cls");
        printf("\n[1] A. Arrange Ascending\n[2] B. Arrange Descending\n\nEnter Choice: ");
        scanf("%d", &choice2);
        if (choice2 == 1)
        {
            printf("\nOutput: ");
            ascending(arr, n);
        }
        else if (choice2 == 2)
        {
            printf("\nOutput: ");
            descending(arr, n);
        }
    }
    return 0;
}