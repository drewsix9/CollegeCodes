#include <stdio.h>

int PrimeOnly(int arr[], int temparr[], int size)
{
    int countPrime = 0;
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
        if (factor == 0)
        {
            temparr[countPrime++] = arr[i];
        }
    }
    return countPrime;
}

int CompOnly(int arr[], int temparr[], int size)
{
    int countComp = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 2; j < arr[i]; j++)
        {
            if (arr[i] % j == 0)
            {
                temparr[countComp++] = arr[i];
                break;
            }
        }
    }
    return countComp;
}

void Ascending(int temparr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (temparr[i] > temparr[j])
            {
                int temp = temparr[i];
                temparr[i] = temparr[j];
                temparr[j] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", temparr[i]);
    }
}

void Descending(int temparr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (temparr[i] < temparr[j])
            {
                int temp = temparr[i];
                temparr[i] = temparr[j];
                temparr[j] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", temparr[i]);
    }
}

int main()
{
    int size;
    printf("Enter number of inputs: ");
    scanf("%d", &size);
    int arr[size], temparr[size];

    printf("Enter inputs: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    int choice1, choice2;
    printf("[1] A. Only Prime\n");
    printf("[2] B. Only Composite\n");
    printf("Enter Choice 1: ");
    scanf("%d", &choice1);

    printf("\n");

    printf("[1] A. Arrange Ascending\n");
    printf("[2] B. Arrange Descending\n");
    printf("Enter Choice 2: ");
    scanf("%d", &choice2);

    int n = 0;
    if (choice1 == 1)
    {
        n = PrimeOnly(arr, temparr, size);
    }
    else if (choice1 == 2)
    {
        n = CompOnly(arr, temparr, size);
    }

    if (choice2 == 1)
    {
        Ascending(temparr, n);
    }
    else if (choice2 == 2)
    {
        Descending(temparr, n);
    }

    return 0;
}