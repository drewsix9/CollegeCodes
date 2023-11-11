#include <stdio.h>

int main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    float sum = 0, average = 0;
    for (int i = 0; i < size; i++)
    {
        printf("Enter elemet #%d: ", i);
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    average = sum / size;

    printf("\nSum: %.0f\n", sum);
    printf("Average: %.2f\n", average);

    return 0;
}