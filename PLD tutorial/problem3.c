#include <stdio.h>

int main()
{
    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);

    int array[size];

    printf("Input %d elements in the array:\n", size);
    for (int i = 0; i < size; i++)
    {
        printf("element: %d : ", i);
        scanf("%d", &array[i]);
        printf("\n");
    }

    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum = sum + array[i];
    }

    printf("\nThe sum of all the input numbers:\n%d", sum);

    return 0;
}