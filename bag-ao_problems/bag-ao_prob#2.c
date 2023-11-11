#include <stdio.h>
#include <stdlib.h>

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

    printf("\nOutput: ");
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

    printf("\nOutput: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int average(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum / n;
}

int sum(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main()
{
    int n, arr[100], choice1, choice2, choice3, stop = 0;
    while (stop != 1)
    {

        printf("\nEnter number of inputs: ");
        scanf("%d", &n);
        printf("\nEnter input(s): ");
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }

        printf("\n[1] - Ascending Output\n[2] - Descending Output\n\nChoose what to output 1st: ");
        scanf("%d", &choice1);
        printf("\n[1] - Average\n[2] - Sum\n\nChoose what to output 2nd: ");
        scanf("%d", &choice2);

        if (choice1 == 1)
        {
            ascending(arr, n);
        }
        else if (choice1 == 2)
        {
            descending(arr, n);
        }

        if (choice2 == 1)
        {
            printf("\nAverage = %d", average(arr, n));
        }
        else if (choice2 == 2)
        {
            printf("\nAverage = %d", sum(arr, n));
        }

        printf("\n\n[1] - REPEAT\n[2] - EXIT\n\nDo you want to enter another input or stop the program?: ");
        scanf("%d", &choice3);

        if (choice3 == 2)
        {
            printf("\n-----BREAK-----");
            stop = 1;
        }
        system("cls");
    }
    return 0;
}