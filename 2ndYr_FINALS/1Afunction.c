#include <stdio.h>
#include <stdbool.h>
#define MAX 100

bool isPrime(int num);

int main()
{
    int num, n = 0, arr[MAX], prime[MAX], prime_n = 0;

    printf("Enter inputs(s): ");
    do
    {
        scanf("%d", &num);
        if (num != 0)
        {
            arr[n] = num;
            n++;
        }
    } while (num != 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j] && isPrime(arr[i]) && isPrime(arr[j]))
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

bool isPrime(int num)
{
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}
