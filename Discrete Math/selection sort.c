#include <stdio.h>

int main()
{
    int arr[8] = {
        6,
        5,
        3,
        1,
        8,
        7,
        2,
        4,
    };
    int size = 8;
    int min = 0;
    int j;
    for (int i = 0; i < size - 1; i++)
    {
        min = i;
        for (j = i + 1; j < size; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}