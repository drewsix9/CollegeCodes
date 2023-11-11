#include <stdio.h>
/*
    sorts the odd numbers ONLY
    10 2 7 4 3 9
    10 2 3 4 7 9
*/

int main()
{
    int size, arr[100], pos[100], n = 0;
    printf("Enter input size: ");
    scanf("%d", &size);

    printf("Enter inputs: ");

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < size; i++)
    {
        // check if ODD
        if (arr[i] % 2 != 0)
        {
            // if ODD, i store  index sa pos[] array
            pos[n++] = i;
        }
    }

    // bubble sort the odd with respect to their positions
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[pos[i]] > arr[pos[j]])
            {
                int temp = arr[pos[i]];
                arr[pos[i]] = arr[pos[j]];
                arr[pos[j]] = temp;
            }
        }
    }

    printf("Output: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}