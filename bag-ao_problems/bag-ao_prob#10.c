#include <stdio.h>
#include <stdlib.h>

int asknumbers(int arr[])
{
    int temp, n = 0;

    printf("Enter inputs (stop = 0): ");
    do
    {
        scanf("%d", &temp);
        if (temp != 0)
        {
            arr[n++] = temp;
        }
    } while (temp != 0);
    return n;
}

int choiceA(int arr[], int factors[], int size)
{
    int largest = arr[0];
    // determining the largest
    for (int i = 1; i < size; i++)
    {
        if (largest < arr[i])
        {
            largest = arr[i];
        }
    }

    int num = largest, rem, l = 0, fn = 0;
    while (l < size)
    {
        rem = num % arr[l];
        if (rem == 0)
        {
            factors[fn++] = arr[l++];
        }
        else
        {
            l++;
        }
    }
    return fn;
}

int choiceB(int arr[], int factors[], int size)
{
    int smallest = arr[0];
    // determining the smallest
    for (int i = 1; i < size; i++)
    {
        if (smallest > arr[i])
        {
            smallest = arr[i];
        }
    }

    int num = smallest, rem, l = 0, fn = 0;
    while (l < size)
    {
        rem = arr[l] % num;
        if (rem == 0)
        {
            factors[fn++] = arr[l++];
        }
        else
        {
            l++;
        }
    }

    return fn;
}

void sortAsc(int factors[], int f_size)
{
    for (int i = 0; i < f_size; i++)
    {
        for (int j = i + 1; j < f_size; j++)
        {
            if (factors[i] > factors[j])
            {
                int temp = factors[i];
                factors[i] = factors[j];
                factors[j] = temp;
            }
        }
    }
}

void sortDesc(int factors[], int f_size)
{
    for (int i = 0; i < f_size; i++)
    {
        for (int j = i + 1; j < f_size; j++)
        {
            if (factors[i] < factors[j])
            {
                int temp = factors[i];
                factors[i] = factors[j];
                factors[j] = temp;
            }
        }
    }
}

int main()
{
    int arr[100], factors[100];

    int size = asknumbers(arr);

    printf("\n[1] - Choice A\n[2] - Choice B\nEnter choice: ");
    int choice;
    scanf("%d", &choice);

    if (choice == 1)
    {
        // execute a
        int f_size = choiceA(arr, factors, size);
        sortAsc(factors, f_size);

        printf("\nOutput: ");
        for (int i = 0; i < f_size; i++)
        {
            printf("%d ", factors[i]);
        }
    }
    else if (choice == 2)
    {
        // execute b
        int f_size = choiceB(arr, factors, size);
        sortDesc(factors, f_size);

        printf("\nOutput: ");
        for (int i = 0; i < f_size; i++)
        {
            printf("%d ", factors[i]);
        }
    }

    return 0;
}
