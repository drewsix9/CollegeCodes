// let the user choose: ascending, descending, prime, comp, EXIT
// enter number of inputs, and the inputs itselves
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
}

void printPrime(int arr[], int size)
{
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
    int choice, stop = 0, n, arr[100];

    while (stop != 1)
    {
        printf("\n[1] - sort in ascending order\n[2] - sort in descending order\n[3] - print only prime\n[4] - print only composite\n[5] - EXIT\n\nEnter your choice: ");
        scanf(" %d", &choice);
        if (choice == 1)
        {
            system("cls");
            printf("Sorting in ascending order... ");
            printf("\nEnter number of inputs: ");
            scanf("%d", &n);
            printf("\nEnter input(s): ");
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &arr[i]);
            }

            ascending(arr, n);

            printf("\nOutput: ");
            for (int i = 0; i < n; i++)
            {
                printf("%d ", arr[i]);
            }
            printf("\n");
        }
        else if (choice == 2)
        {
            system("cls");
            printf("Sorting in descending order... ");
            printf("\nEnter number of inputs: ");
            scanf("%d", &n);
            printf("\nEnter input(s): ");
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &arr[i]);
            }

            descending(arr, n);

            printf("\nOutput: ");
            for (int i = 0; i < n; i++)
            {
                printf("%d ", arr[i]);
            }
            printf("\n");
        }
        else if (choice == 3)
        {
            system("cls");
            printf("Printing only prime... ");
            printf("\nEnter number of inputs: ");
            scanf("%d", &n);
            printf("\nEnter input(s): ");
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &arr[i]);
            }

            printf("\nOutput: ");
            printPrime(arr, n);
            printf("\n");
        }
        else if (choice == 4)
        {
            system("cls");
            printf("Printing only composite... ");
            printf("\nEnter number of inputs: ");
            scanf("%d", &n);
            printf("\nEnter input(s): ");
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &arr[i]);
            }

            printf("\nOutput: ");
            printComp(arr, n);
            printf("\n");
        }
        else if (choice == 5)
        {
            system("cls");
            printf("----BREAK----");
            stop = 1;
        }
    }
    return 0;
}
