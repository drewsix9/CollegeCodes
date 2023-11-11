#include <stdio.h>
#include <string.h>

#define MAX 1000

int main()
{
    int num = 1211;
    int arr[MAX];
    int newarr[MAX];

    int rem, n = 4;
    while (num != 0)
    {
        rem = num % 10;
        arr[n] = rem;
        n--;
        num /= 10;
    }

    n = 4;
    int j = 0;

    for (int i = 0; i < n; i++)
    {
        int count = 1;
        int temp = arr[i];

        while (arr[i] == arr[i + 1])
        {
            count++;
            i++;
        }
        newarr[j] = count;
        j++;
        newarr[j] = temp;
        j++;
    }
    for (int i = 0; i < j; i++)
    {
        printf("%d", newarr[i]);
    }
    return 0;
}