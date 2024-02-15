#include <stdio.h>

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

int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (isPrime(num) == 0)
    {
        printf("Output: ");
        for (int i = 2; i < num; i++)
        {
            if (num % i == 0)
            {
                printf("%d ", i);
            }
        }

        printf("\n%d is a Composite number.", num);
    }
    else if (isPrime(num))
    {
        for (int i = 0; i <= num; i++)
        {
            if (isPrime(i) == 1)
            {
                printf("%d ", i);
            }
        }
        printf("\n%d is a Prime number.", num);
    }
    return 0;
}