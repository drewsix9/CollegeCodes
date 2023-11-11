// Create a program that searches an element of an array of integer from user input, if the element is found, return the index.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    while (1)
    {
        printf("\nEnter array (0 to stop): ");

        int n = 0, temp, arr[100];
        while (scanf("%d", &temp) == 1 && temp != 0)
        {
            arr[n++] = temp;
        }

        int target = 0;
        printf("\nEnter integer to search: ");
        scanf("%d", &target);

        int j = 0;
        while (j < n && arr[j] != target)
        {
            j++;
        }

        if (j < n)
        {
            printf("\n%d is found at index %d", target, j);
        }
        else
        {
            printf("\n%d is NOT found!", target);
        }
        printf("\n\nPress any key to continue... ");
        getch();
        system("cls");
    }

    return 0;
}
