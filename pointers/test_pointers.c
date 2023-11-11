#include <stdio.h>

void printarray(int *array)
{
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", *array++);
    }
}

int main()
{
    int arr[5] = {2, 4, 6, 8, 10};
    printarray(arr);

    return 0;
}