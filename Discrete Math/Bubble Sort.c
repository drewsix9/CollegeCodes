// Create a program that takes in an array of integers and lets the user decide whether to sort in increasing or decreasing order.

#include <stdio.h>

int main()
{
    while (1)
    {
        int n = 0, temp = 0, arr[100];
        printf("\nEnter array (0 to stop): ");
        while (scanf("%d", &temp) && temp != 0)
        {
            arr[n++] = temp;
        }

        int choice = 0;
        printf("\n[1] - Increasing Order\n[2] - Decreasing Order\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n - 1; j++)
                {
                    if (arr[j] > arr[j + 1])
                    {
                        temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }
        }

        else if (choice == 2)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n - 1; j++)
                {
                    if (arr[j] < arr[j + 1])
                    {
                        temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }
        }

        printf("\nOutput: ");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n\nPress any key to continue... ");
        getch();
        system("cls");
    }

    return 0;
}