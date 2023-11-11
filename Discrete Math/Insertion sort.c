#include <stdio.h>

int main()
{
    int arr[8] = {6, 5, 3, 1, 8, 7, 2, 4,};
    int size = 8;
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (key < arr[j] && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}