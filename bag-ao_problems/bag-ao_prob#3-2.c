#include <stdio.h>

int isPrime(int num)
{
    if (num == 1)
    {
        return 0;
    }
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

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

void onlyPrime(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (isPrime(arr[i]) == 1)
        {
            printf("%d ", arr[i]);
        }
    }
}

void onlyComp(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (isPrime(arr[i]) == 0)
        {
            printf("%d ", arr[i]);
        }
    }
}

int main()
{
    int size;
    printf("Enter number of inputs: ");
    scanf("%d", &size);

    printf("Enter inputs: ");
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("1 - ascending\n2 - descending\n3 - print prime only\n4 - print comp only");

    int num, option_arr[100], n = 0;
    printf("\n\nEnter options: ");
    while (scanf("%d", &num) == 1 && num != 0)
    {
        option_arr[n++] = num;
    }

    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("Output %d: ", i + 1);
        if (option_arr[i] == 1)
        {
            Ascending(arr, size);
            for (int i = 0; i < size; i++)
            {
                printf("%d ", arr[i]);
            }
        }
        else if (option_arr[i] == 2)
        {
            Descending(arr, size);
            for (int i = 0; i < size; i++)
            {
                printf("%d ", arr[i]);
            }
        }
        else if (option_arr[i] == 3)
        {
            onlyPrime(arr, size);
        }
        else if (option_arr[i] == 4)
        {
            onlyComp(arr, size);
        }
        printf("\n");
    }

    return 0;
}