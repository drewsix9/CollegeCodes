#include <stdio.h>

void array_reversal(int *num, int len);

int main()
{

    int arr[10] = {10, 2, 9, 15, 13, 24, 44, 17, 16, 19};
    int len = 10;

    array_reversal(arr, len);

    printf("\n");
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

void array_reversal(int *num, int len)
{

    for (int i = 0; i < len / 2; i++)
    {
        int temp = num[i];
        num[i] = num[len - i - 1];
        num[len - i - 1] = temp;
    }
}