#include <stdio.h>
#include <stdlib.h>

void allprimefrom2to100(int prime[])
{

    int k = 0;
    for (int i = 2; i < 100; i++)
    {
        int factor = 0;
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                factor++;
                break;
            }
        }
        if (factor == 0)
        {
            prime[k++] = i;
        }
    }
}

int main()
{

    int h = 0, l = 0, primef[100], prime[100], rem, quot, num;

    allprimefrom2to100(prime);

    printf("Enter input: ");
    scanf("%d", &num);

    for (;;)
    {
        quot = num / prime[l];
        rem = num % prime[l];
        if (rem == 0)
        {
            primef[h++] = prime[l];
            num = quot;
        }
        else
        {
            l++;
        }
        if (quot == 0)
        {
            break;
        }
    }

    for (int i = 0; i < h; i++)
    {
        printf("%d ", primef[i]);
        if (i == h - 1)
        {
            continue;
        }
        printf("* ");
    }

    return 0;
}