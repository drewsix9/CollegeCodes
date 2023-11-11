// Create a program that takes in an array of integer (sorted in increasing order) from user input and a key value to be searched in the array.

#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int JumpSearch(int arr[], int size, int key)
{
    int left = 0;
    int right = sqrt(size);

    while (arr[right] <= key && right < size)
    {
        left = right;
        right += sqrt(size);
        if (right > size - 1)
        {
            right = size;
        }
    }

    for (int i = left; i < right; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    while (1)
    {

        int arr[100], temp = 0, n = 0;
        printf("\nEnter array (0 to stop): ");
        while (scanf("%d", &temp) && temp != 0)
        {
            arr[n++] = temp;
        }

        int key = 0;
        printf("\nEnter key value: ");
        scanf("%d", &key);

        int result = JumpSearch(arr, n, key);
        if (result == -1)
        {
            printf("\n%d is NOT found!", key);
        }
        else
        {
            printf("\n%d is found at index %d", key, result);
        }
        printf("\nEnter any key to continue... ");
        getch();
        system("cls");
    }

    return 0;
}