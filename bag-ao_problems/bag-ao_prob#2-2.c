#include <stdio.h>
#include <stdlib.h>

void Ascending(int *arr, int size)
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

void Descending(int *arr, int size)
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

float Average(int *arr, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }

    return (float)sum / size;
}

int Sum(int *arr, int size)
{
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }

    return sum;
}

int main()
{
    int size, arr[100];
    printf("Enter number of inputs: ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    int stop = 0;
    while (stop != 1)
    {
        int choice1 = 0, choice2 = 0;

        printf("First Output:\n1 - Ascending\n2 - Descending\nEnter Choice: ");
        scanf("%d", &choice1);

        printf("Second Output:\n1 - Average\n2 - Sum\nEnter Choice: ");
        scanf("%d", &choice2);

        if (choice1 == 1)
        {
            Ascending(arr, size);
            printf("\n");
            for (int i = 0; i < size; i++)
            {
                printf("%d ", arr[i]);
            }
            printf("\n");
        }
        else if (choice1 == 2)
        {
            Descending(arr, size);
            printf("\n");
            for (int i = 0; i < size; i++)
            {
                printf("%d ", arr[i]);
            }
            printf("\n");
        }

        if (choice2 == 1)
        {
            printf("\nAverage = %f", Average(arr, size));
        }
        else if (choice2 == 2)
        {
            printf("\nSum = %d", Sum(arr, size));
        }

        printf("\n\n1 - Continue or Repeat for another Ouput\n2 - Exit or stop the program\nEnter choice: ");

        int choice3;
        scanf("%d", &choice3);

        if (choice3 == 1)
        {
            system("cls");
        }
        else if (choice3 == 2)
        {
            stop = 1;
        }
    }
}