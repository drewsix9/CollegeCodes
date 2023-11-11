#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int hasletterO(int num)
{
    int temp = num, rem, place = 1;
    if ((num == 11) || (num == 12))
    {
        return 0;
    }
    for (;;)
    {
        rem = temp % 10;
        if ((rem == 1 && place != 2) || (rem == 2 && place != 2) || (rem == 4))
        {
            return 1;
        }
        temp = temp / 10;
        if (temp == 0)
        {
            break;
        }
        place++;
    }
    if ((place == 4) || (place == 6))
    {
        return 1;
    }
    return 0;
}

int hasletterU(int num)
{
    int temp = num, rem, place = 1;
    if ((num >= 40 && num <= 49) && num != 44)
    {
        return 0;
    }
    for (;;)
    {
        rem = temp % 10;
        if ((rem == 4))
        {
            return 1;
        }
        temp = temp / 10;
        if (temp == 0)
        {
            break;
        }
        place++;
    }
    if ((place == 3) || (place == 4))
    {
        return 1;
    }
    return 0;
}

int hasletterE(int num)
{
    int temp = num, rem, place = 1;
    // if ((num >= 50 && num <= 59) && (num != 50 || num != 52 || num != 54 || num != 56))
    // {
    //     return false;
    // }

    if (num == 50 || num == 52 || num == 54 || num == 56)
    {
        return 0;
    }
    for (;;)
    {
        rem = temp % 10;
        if ((rem == 1) || (rem == 3 && place != 2) || (rem == 5) || (rem == 7) || (rem == 8) || (rem == 9) || (rem == 2 && place == 2))
        {
            return 1;
        }
        temp = temp / 10;
        if (temp == 0)
        {
            break;
        }
        place++;
    }
    if ((place == 3) || (place == 4))
    {
        return 1;
    }
    return 0;
}

int main()
{
    int choice, n, arr[100];
    do
    {
        printf("o-o-o-o-o-o-o-o-o-o-o-o\n  [1] - O-Ban Numbers\n  [2] - U-Ban Numbers\n  [3] - E-Ban Numbers\n  [4] - EXIT\no-o-o-o-o-o-o-o-o-o-o-o\n\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) // O-ban
        {
            system("cls");
            printf("Banning letter O... ");
            printf("\nEnter how many inputs: ");
            scanf("%d", &n);
            printf("\nEnter input(s): ");
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &arr[i]);
            }
            printf("\nOutput: ");
            for (int i = 0; i < n; i++)
            {
                if (hasletterO(arr[i]) == 0)
                {
                    printf("%d ", arr[i]);
                }
            }
            printf("\n\n");
        }
        else if (choice == 2) // U-ban
        {
            system("cls");
            printf("Banning letter U... ");
            printf("\nEnter how many inputs: ");
            scanf("%d", &n);
            printf("\nEnter input(s): ");
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &arr[i]);
            }
            printf("\nOutput: ");
            for (int i = 0; i < n; i++)
            {
                if (hasletterU(arr[i]) == 0)
                {
                    printf("%d ", arr[i]);
                }
            }
            printf("\n\n");
        }
        else if (choice == 3) // E-ban
        {
            system("cls");
            printf("Banning letter E... ");
            printf("\nEnter how many inputs: ");
            scanf("%d", &n);
            printf("\nEnter input(s): ");
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &arr[i]);
            }
            printf("\nOutput: ");
            for (int i = 0; i < n; i++)
            {
                if (hasletterE(arr[i]) == 0)
                {
                    printf("%d ", arr[i]);
                }
            }
            printf("\n\n");
        }
    } while (choice != 4);
    return 0;
}