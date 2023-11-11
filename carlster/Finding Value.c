#include <stdio.h>

int main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++)
    {
        printf("Enter element #%d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    int value;
    printf("Enter a value to search for: ");
    scanf("%d", &value);

    int isFound = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == value)
        {
            isFound = 1;
        }
    }

    if (isFound == 1)
    {
        printf("Found!");
    }
    else
    {
        printf("Sorry, %d not found", value);
    }

    return 0;
}