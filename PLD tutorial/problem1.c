#include <stdio.h>
// Write a program in C to read in n numbers of values in an array and ddisplay them in reverse order.
int main()
{
    int size;
    printf("Input the number of elements to store in the array: ");
    scanf("%d", &size);
    int array[size];
    printf("Input %d number of elements in the array:\n", size);
    for (int i = 0; i < size; i++)
    {
        printf("Element - %d : ", i);
        scanf("%d", &array[i]);
    }

    printf("The values store into the array are:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\nThe values store into the array in reverse are:\n");
    for (int i = size - 1; i >= 0; i--)
    {
        printf("%d ", array[i]);
    }
}