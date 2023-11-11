#include <stdio.h>

// Function to remove duplicates from an array using binary search
int removeDuplicates(int arr[], int n)
{
    int i, j, k;
    int count = 0;

    // Sort the array in ascending order
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Remove duplicates using binary search, basically overwriting the array if it is a unique element.
    for (i = 0; i < n; i++)
    {
        if (arr[i] != arr[i + 1])
        {
            arr[count++] = arr[i];
        }
    }

    // Print the array without duplicates
    printf("Array without duplicates: ");
    for (i = 0; i < count; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return count;
}

// Driver code
int main()
{
    int arr[] = {10, 11, 10, 11, 122, 23, 2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int count = removeDuplicates(arr, n);

    printf("Number of unique elements: %d\n", count);

    return 0;
}