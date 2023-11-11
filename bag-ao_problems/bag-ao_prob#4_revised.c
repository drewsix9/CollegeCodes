#include <stdio.h>
#include <stdlib.h>

int countprime(int n, int arr[], int newarr[])
{
    int nn = 0;
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
            newarr[nn] = arr[i];
            nn++;
        }
    }
    return nn;
}

int countcomp(int n, int arr[], int newarr[])
{
    int nn = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 2; j < arr[i]; j++)
        {
            if (arr[i] % j == 0)
            {
                newarr[nn] = arr[i];
                nn++;
                break;
            }
        }
    }
    return nn;
}

void printarray(int newarr[], int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("%d ", newarr[i]);
    }
}

void ascending(int newarr[], int count)
{
    for (int i = 0; i < count; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (newarr[i] > newarr[j])
            {
                int temp = newarr[i];
                newarr[i] = newarr[j];
                newarr[j] = temp;
            }
        }
    }
    printarray(newarr, count);
}

void descending(int newarr[], int count)
{
    for (int i = 0; i < count; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (newarr[i] < newarr[j])
            {
                int temp = newarr[i];
                newarr[i] = newarr[j];
                newarr[j] = temp;
            }
        }
    }
    printarray(newarr, count);
}

int main()
{
    int choice1, choice2, n, newarr[100], count;
    printf("Enter no. of inputs: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter input(s): ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nChoice 1:\n     [1] Only Prime\n     [2] Only Composite\n");
    printf("\nEnter Choice: ");
    scanf("%d", &choice1);
    printf("\nChoice 2:\n     [1] Arrange Ascending\n     [2] Arrange Descending\n");
    printf("\nEnter Choice: ");
    scanf("%d", &choice2);

    if (choice1 == 1)
    {
        count = countprime(n, arr, newarr);
        printf("\nOutput: ");
        printarray(newarr, count);
    }
    else if (choice1 == 2)
    {
        count = countcomp(n, arr, newarr);
        printf("\nOutput: ");
        printarray(newarr, count);
    }

    if (choice2 == 1)
    {
        printf("\nOutput: ");
        ascending(newarr, count);
    }
    else if (choice2 == 2)
    {
        printf("\nOutput: ");
        descending(newarr, count);
    }
    return 0;
}