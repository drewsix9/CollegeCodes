#include <stdio.h>
/*
    remove prime duplicates
    input: 10 10 2 5 2
    output: 10 10 5
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
    int arr[100], size;
    printf("Enter # of inputs: ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    int freq[size];
    // set all values of freq to -1
    for (int i = 0; i < size; i++)
    {
        freq[i] = -1;
    }

    for (int i = 0; i < size; i++)
    {
        int count = 1;
        for (int j = i + 1; j < size; j++)
        {
            if (isPrime(arr[i]) && isPrime(arr[j]) && arr[i] == arr[j])
            {
                // if prime ang duha tas equal pa jd, set to 0 na ilang freq
                count++;
                freq[i] = 0;
                freq[j] = 0;
            }
        }
        if (freq[i] != 0)
        {
            freq[i] = count;
        }
    }

    printf("\nOutput: ");
    for (int i = 0; i < size; i++)
    {
        // i print ang DILE 0 ang freq
        if (freq[i] != 0)
        {
            printf("%d ", arr[i]);
        }
    }
    return 0;
}