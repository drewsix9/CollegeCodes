#include <stdio.h>

int isPrime(int num)
{
    if (num == 1)
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
    int rows, arr[100][100];
    printf("Enter number of sets: ");
    scanf("%d", &rows);
    int colsize[rows];

    int temp;
    for (int i = 0; i < rows; i++)
    {
        int j = 0;
        while (scanf("%d", &temp) == 1 && temp != 0)
        {
            arr[i][j++] = temp;
        }
        colsize[i] = j;
    }

    int newarr[100], n = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < colsize[i]; j++)
        {
            if (isPrime(arr[i][j]) == 1)
            {
                newarr[n++] = arr[i][j];
            }
        }
    }

    int freq[n];
    for (int i = 0; i < n; i++)
    {
        freq[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        int count = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (newarr[i] == newarr[j])
            {
                count++;
                freq[j] = 0;
            }
        }
        if (freq[i] != 0)
        {
            freq[i] = count;
        }
    }

    printf("\nOutput:\n");
    for (int i = 0; i < n; i++)
    {
        if (freq[i] > 0)
        {
            printf("%d ", newarr[i]);
        }
    }
    return 0;
}