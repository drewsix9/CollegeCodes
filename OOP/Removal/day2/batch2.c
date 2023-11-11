#include <stdio.h>

/*
    insert the value before a prime number

    input: 2 3 9 13 12 8 5
    insert value: 10
    output: 10 2 10 3 9 10 13 12 8 10 5
*/

int isPrime(int num)
{
    if (num <= 1)
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

int main()
{
    int temp, arr[100], size = 0, insert = 0;
    printf("Enter inputs (0 to stop): ");
    while (scanf("%d", &temp) && temp != 0)
    {
        arr[size++] = temp;
    }

    printf("Enter num to insert: ");
    scanf("%d", &insert);

    printf("\nOutput: ");
    // basahon niya isa2 ang num sa imo array
    for (int i = 0; i < size; i++)
    {
        if (isPrime(arr[i]))
        {
            // if prime ang number, i print nimo ang insert value una aysa ang num
            printf("%d %d ", insert, arr[i]);
        }
        else
        {
            // ug dile prime, largo ra print ang num
            printf("%d ", arr[i]);
        }
    }

    return 0;
}