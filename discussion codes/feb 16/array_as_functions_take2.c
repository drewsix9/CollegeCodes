#include <stdio.h>
#include <stdbool.h>

#include <stdlib.h>

// A - 0 = 1, 2, 4,
// B - U = 4;
// C - E = 1, 3, 5, 7, 8, 9, 0
// D - EXIT

void printBanO(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int isBanned = 0;
        int place = 1;
        int temp = arr[i];
        for (;;)
        {
            if ((temp % 10 == 1 && (place == 1 || place == 3)) || ((temp % 10 == 1 && place == 1) && (temp % 10 == 1 && place == 2)) || (temp % 10 == 2 && (place == 1 || place == 3)) || (temp % 10 == 4 && (place == 1 || place == 3)) || (temp % 10 == 4 && place == 2) || place == 4 || place == 6)
            {
                isBanned++;
                break;
            }
            temp = temp / 10;
            if (temp == 0)
            {
                break;
            }
            place++;
        }
        if (isBanned == 0)
        {
            printf("%d ", arr[i]);
        }
    }
}

void printBanU(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int isBanned = 0;
        int place = 1;
        int temp = arr[i];
        for (;;)
        {
            if ((temp % 10 == 4 && place == 1) || arr[i] == 14 || place == 3 || place == 4)
            {
                isBanned++;
                break;
            }
            temp = temp / 10;
            if (temp == 0)
            {
                break;
            }
            place++;
        }
        if (isBanned == 0)
        {
            printf("%d ", arr[i]);
        }
    }
}

void printBanE(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int isBanned = 0;
        int place = 1;
        int temp = arr[i];
        for (;;)
        {
            if ((temp % 10 == 1 && place == 1) || (temp % 10 == 3 && place == 1) || (temp % 10 == 5 && place == 1) || (temp % 10 == 7 && place == 1) || (temp % 10 == 8 && place == 1) || (temp % 10 == 9 && place == 1) || (arr[i] >= 10 && arr[i] <= 19) || (temp % 10 == 2 && place == 2) || (temp % 10 >= 7 && temp % 10 <= 9 && place == 2) || place == 3)
            {
                isBanned++;
                break;
            }
            temp = temp / 10;
            if (temp == 0)
            {
                break;
            }
            place++;
        }
        if (isBanned == 0)
        {
            printf("%d ", arr[i]);
        }
    }
}

int main()
{
    char choice;
    int stop = 0, n = 0, arr[100];

    while (stop != 1)
    {
        choice = 0;
        printf("\n[A] - 'O' Ban\n[B] - 'U' Ban\n[C] - 'E' Ban\n[D] - EXIT\nEnter Choice: ");
        scanf(" %c", &choice);
        if (choice == 'A' || choice == 'a')
        {
            system("cls");
            printf("Banning 'O'...\n");
            printf("\nEnter how many numbers: ");
            scanf("%d", &n);
            printf("\nEnter numbers: ");
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &arr[i]);
            }
            printf("\nOutput: ");
            printBanO(arr, n);
            printf("\n");
        }
        else if (choice == 'B' || choice == 'b')
        {
            system("cls");
            printf("Banning 'U'...\n");
            printf("\nEnter how many numbers: ");
            scanf("%d", &n);
            printf("\nEnter numbers: ");
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &arr[i]);
            }
            printf("\nOutput: ");
            printBanU(arr, n);
            printf("\n");
        }
        else if (choice == 'C' || choice == 'c')
        {
            system("cls");
            printf("Banning 'E'...\n");
            printf("\nEnter how many numbers: ");
            scanf("%d", &n);
            printf("\nEnter numbers: ");
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &arr[i]);
            }
            printf("\nOutput: ");
            printBanE(arr, n);
            printf("\n");
        }
        else if (choice == 'D' || choice == 'd')
        {
            system("cls");
            printf("-----BREAK-----");
            stop = 1;
        }
    }
}
