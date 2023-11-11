#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define MAX 100
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

int countDigits(int num)
{
    // with respect to index counting
    int place = 0;
    for (;;)
    {
        num /= 10;
        place++;
        if (num == 0)
        {
            break;
        }
    }
    return place;
}

int reverse(int num)
{
    int rem = 0, count = countDigits(num), prod = 0, sum = 0;
    for (;;)
    {
        rem = num % 10;
        prod = rem * pow(10, count);
        num /= 10;
        sum += prod;
        count--;
        if (num == 0)
        {
            break;
        }
    }
    return sum;
}

void lookNsay(int num, int max)
{
    int rem, sum = 0, toArr[MAX];
    printf("\nOutput : \n%d", num);

    for (int i = 0; i < max; i++)
    {
        int temp = num;
        int Ndigit = countDigits(temp); // count digits

        for (int i = 0; toArr[i] != NULL; i++) // resetting the array
        {
            toArr[i] = NULL;
        }

        for (int i = Ndigit - 1; i >= 0; i--)
        {
            rem = temp % 10;
            toArr[i] = rem;
            temp /= 10;
        }
        sum = 0;
        for (int i = 0; i < Ndigit; i++)
        {
            int count = 0;
            int counter = 0;
            int j = i;
            while (toArr[i] == toArr[j])
            {
                count++;
                j++;
            }
            j = i;
            while (toArr[i] == toArr[j])
            {
                counter++;
                j--;
            }
            if (counter == 1)
            {
                sum = sum * 10;
                sum = (sum + count) * 10;
                sum = sum + toArr[i];
            }
        }
        printf("\n%d", sum);
        num = sum;
    }
}

int LargPrime(int prime[], int prime_n)
{
    for (int i = 0; i < prime_n; i++)
    {
        for (int j = i + 1; j < prime_n; j++)
        {
            if (prime[i] > prime[j])
            {
                int temp = prime[i];
                prime[i] = prime[j];
                prime[j] = temp;
            }
        }
    }
    return prime[prime_n - 1];
}

int main()
{
    int n, arr[MAX], prime[MAX], prime_n = 0;
    printf("Enter number of inputs: ");
    scanf("%d", &n);
    printf("\nEnter input(s):");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (isPrime(arr[i]) == 1)
        {
            prime[prime_n] = arr[i];
            prime_n++;
        }
    }

    lookNsay(LargPrime(prime, prime_n), n - 1);
    return 0;
}
