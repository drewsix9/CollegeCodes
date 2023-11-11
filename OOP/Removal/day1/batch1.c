#include <stdio.h>

/*
Ask inputs nya print largest composite og smallest with their prime factors
*/

int isPrime(int num)
{
    if (num <= 1)
        return 0;

    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

void primefactorization(int num)
{
    // storing all prime numbers in an array
    int prime[100], prime_n = 0;
    for (int i = 1; i < 100; i++)
    {
        if (isPrime(i))
        {
            prime[prime_n++] = i;
        }
    }

    int rem = 0, quot;
    int i = 0;
    for (;;)
    {
        quot = num / prime[i];
        rem = num % prime[i];
        if (rem == 0) // current prime number is divisible
        {
            printf("%d ", prime[i]);
            num = quot;
        }
        else // current prime number is NOT divisible
        {
            // proceed to the next prime number in the array
            i++;
        }
        if (quot == 0)
        {
            break;
        }
    }
}

int main()
{

    int temp, arr[100], n = 0;

    printf("Enter inputs (0 to stop): ): ");
    while (scanf("%d", &temp) != NULL && temp != 0)
    {
        arr[n++] = temp;
    }

    int LargComp = 0, SmallComp = arr[0];
    printf("\nOutput:\n");
    for (int i = 0; i < n; i++)
    {
        if (!isPrime(arr[i]))
        {
            if (LargComp < arr[i])
            {
                LargComp = arr[i];
            }
            if (SmallComp > arr[i])
            {
                SmallComp = arr[i];
            }
        }
    }

    printf("%d = ", LargComp);
    primefactorization(LargComp);
    printf("\n");
    printf("%d = ", SmallComp);
    primefactorization(SmallComp);

    return 0;
}