#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int isBinary(int num)
{
    while (num > 0)
    {
        int digit = num % 10;
        if (digit != 0 && digit != 1)
        {
            return 0;
        }
        num /= 10;
    }
    return 1;
}

int isOctal(int num)
{
    while (num > 0)
    {
        int digit = num % 10;
        if (digit >= 8)
        {
            return 0;
        }
        num /= 10;
    }
    return 1;
}

int isPrime(int num)
{
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int Binary_Deci(int arr[], int final_arr[], int size)
{
    int final_arr_size = 0;
    for (int i = 0; i < size; i++)
    {
        if (isBinary(arr[i]))
        {
            int num = arr[i];
            int rem = 0, prod = 0, sum = 0, n = 0;
            while (num > 0)
            {
                rem = num % 10;
                prod = rem * pow(2, n++);
                sum += prod;
                num /= 10;
            }
            final_arr[i] = sum;
            final_arr_size++;
        }
    }
    return final_arr_size;
}

int Octal_Deci(int arr[], int final_arr[], int size)
{
    int final_arr_size = 0;
    for (int i = 0; i < size; i++)
    {
        if (isOctal(arr[i]))
        {
            int num = arr[i];
            int rem = 0, prod = 0, sum = 0, n = 0;
            while (num > 0)
            {
                rem = num % 10;
                prod = rem * pow(8, n++);
                sum += prod;
                num /= 10;
            }
            final_arr[i] = sum;
            final_arr_size++;
        }
    }
    return final_arr_size;
}

int PrimeOnly(int final_arr[], int final_arr_size)
{
    int sizeminus = 0;
    for (int i = 0; i < final_arr_size; i++)
    {
        if (!isPrime(final_arr[i]))
        {
            sizeminus++;
            for (int j = i; j < final_arr_size; j++)
            {
                final_arr[j] = final_arr[j + 1];
            }
        }
    }
    return sizeminus;
}

int CompOnly(int final_arr[], int final_arr_size)
{
    int sizeminus;
    for (int i = 0; i < final_arr_size; i++)
    {
        if (isPrime(final_arr[i]))
        {
            sizeminus++;
            for (int j = i; j < final_arr_size; j++)
            {
                final_arr[j] = final_arr[j + 1];
            }
        }
    }
    return sizeminus;
}

int gettingLargest(int final_arr[], int size, int sizeminus)
{
    int largest = final_arr[0];
    for (int i = 1; i < (size - sizeminus); i++)
    {
        if (largest < final_arr[i])
        {
            largest = final_arr[i];
        }
    }
    return largest;
}

int gettingSmallest(int final_arr[], int size, int sizeminus)
{
    int smallest = final_arr[0];
    for (int i = 1; i < (size - sizeminus); i++)
    {
        if (smallest > final_arr[i])
        {
            smallest = final_arr[i];
        }
    }
    return smallest;
}

int gettingLCM(int smallest, int largest)
{
    int lcm = smallest;
    for (;;)
    {
        if (lcm % largest == 0 && lcm % smallest == 0)
        {
            return lcm;
        }
        lcm++;
    }
}

int main()
{
    int size, final_arr_size, sizeminus;
    char choice1, choice2;
    printf("Enter number of inputs: ");
    scanf("%d", &size);
    int arr[size];
    int final_arr[size];

    printf("Enter inputs: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nChoice 1\nA. Convert Binary to decimal\nB. Convert Octal to decimal\n\nEnter choice1: ");
    scanf(" %c", &choice1);
    printf("\nChoice 2\nA. Prime Numbers Only\nB. Composite Numbers only\n\nEnter choice2: ");
    scanf(" %c", &choice2);

    if (choice1 == 'a' || choice1 == 'A')
    {
        final_arr_size = Binary_Deci(arr, final_arr, size);
    }
    else if (choice1 == 'b' || choice1 == 'B')
    {
        final_arr_size = Octal_Deci(arr, final_arr, size);
    }

    if (choice2 == 'a' || choice2 == 'A')
    {
        sizeminus = PrimeOnly(final_arr, final_arr_size);
    }
    else if (choice2 == 'b' || choice2 == 'B')
    {
        sizeminus = CompOnly(final_arr, final_arr_size);
    }

    printf("\nOutput: ");
    for (int i = 0; i < (size - sizeminus); i++)
    {
        printf("%d ", final_arr[i]);
    }

    int largest = gettingLargest(final_arr, size, sizeminus);
    int smallest = gettingSmallest(final_arr, size, sizeminus);
    int lcm = gettingLCM(smallest, largest);
    printf("\nLeast common multiple of %d and %d : %d", smallest, largest, lcm);

    return 0;
}
