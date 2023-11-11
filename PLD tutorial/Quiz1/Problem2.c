#include <stdio.h>
int main()
{
    int arr[100];
    int size;
    printf("Enter number of inputs: ");
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    // initialize array freq[] and its starting value will be -1
    int freq[size];
    for (int i = 0; i < size; i++)
    {
        freq[i] = -1;
    }

    // the loop where counting the frequency of the numbers
    for (int i = 0; i < size; i++)
    {
        int count = 1;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] == arr[j])
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

    printf("\n");
    for (int i = 0; i < size; i++)
    {
        // only prints the number and its freq if the number appeared atleast twice
        if (freq[i] >= 2)
        {
            printf("%d appeared %d\n", arr[i], freq[i]);
        }
    }
    return 0;
}