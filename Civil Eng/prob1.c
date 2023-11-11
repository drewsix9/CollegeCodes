#include <stdio.h>
int main()
{
    int input = 0;
    printf("Enter input: ");
    scanf("%d", &input);

    printf("\nOutput: ");
    // to check if num is prime
    int isPrime = 1;
    for (int i = 2; i < input; i++)
    {
        if (input % i == 0)
        {
            // if kita siya ug divislbe na number, isPrime is set to 0
            isPrime = 0;
            break;
        }
    }

    if (isPrime == 1)
    {
        // if input is prime
        for (int i = input; i >= 1; i--)
        {
            if (i % 2 == 0)
            {
                printf("%d ", i);
            }
        }
    }
    else
    {
        // if input is not prime
        int i = 0;
        while (i < input)
        {
            if (i % 2 != 0)
            {
                // if 'i' is not divisible by 2, print
                printf("%d ", i);
            }
            i++;
        }
    }
    return 0;
}