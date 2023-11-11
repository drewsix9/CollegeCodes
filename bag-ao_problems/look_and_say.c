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

int countDigits(int num)
{
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
    return place - 1;
}

void toArray(int toArr[], int num)
{
    int rem, n = countDigits(num);
    while (num != 0)
    {
        rem = num % 10;
        toArr[n] = rem;
        n--;
        num /= 10;
    }
}

void lookNsay(int num, int toArr[], int newarr[])
{
    toArray(toArr, num);
    int n = countDigits(num);
    int j = 0;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        count = 0;
        int temp = toArr[i];

        while (toArr[i] == toArr[i + 1])
        {
            count++;
            i++;
        }
        newarr[j] = count;
        printf("%d ", newarr[j]);
        j++;
        newarr[j] = temp;
        printf("%d ", newarr[j]);
        j++;
    }
}

int main()
{
    int n, arr[MAX], toArr[MAX], newarr[MAX];
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
            lookNsay(arr[i], toArr, newarr);
        }
    }
    return 0;
}