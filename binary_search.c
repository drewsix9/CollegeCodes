#include <stdio.h>

int main()
{
    int arr[100];
    int num;
    int target;
    int size = 0;
    int mid, low = 0, high = 8;
    int i = 1;

    printf("Enter array: ");
    while (scanf("%d,", &num) == 1 && num != 0)
    {
        arr[size++] = num;
    }

    printf("Enter target: ");
    scanf("%d", &target);
    printf("\n");

    while (arr[mid] != target)
    {
        mid = (low + high) / 2;
        if (arr[mid] > target)
        {
            high = mid - 1;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        printf("Iteration %d: low: %d\thigh: %d\t mid: %d\n", i++, low, high, mid);
    }
    printf("\nFound your target at index: %d", mid);
    return 0;
}