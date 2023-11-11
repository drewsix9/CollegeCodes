#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
int A, B, C;
void convert_to_words(int num);
void checkletters(char word[]);

int main()
{
    char choice;
    int i, n, arr[100];
    printf("Ban\nA - O\nB - U\nC - E\nD - EXIT");
    printf("\nEnter your choice:");
    scanf("%ch", &choice);

    if (choice == 'A' || choice == 'a')
    {
        system("cls");
        printf("\nBanning letter 'O'");
        printf("\nEnter how many numbers: ");
        scanf("%d", &n);
        printf("\nEnter the numbers: ");
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
            convert_to_words(arr[i]);
            if (A == 0)
            {
                printf("%d ", arr[i]);
            }
            else
            {
                printf("- ", arr[i]);
            }
        }
    }
    if (choice == 'B' || choice == 'b')
    {
        system("cls");
        printf("\nBanning letter 'U'");
        printf("\nEnter how many numbers: ");
        scanf("%d", &n);
        printf("\nEnter the numbers: ");
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
            convert_to_words(arr[i]);
            if (B == 0)
            {
                printf("%d ", arr[i]);
            }
            else
            {
                printf("- ", arr[i]);
            }
        }
    }
    if (choice == 'C' || choice == 'c')
    {
        system("cls");
        printf("\nBanning letter 'E'");
        printf("\nEnter how many numbers: ");
        scanf("%d", &n);
        printf("\nEnter the numbers: ");
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
            convert_to_words(arr[i]);
            if (C == 0)
            {
                printf("%d ", arr[i]);
            }
            else
            {
                printf("- ", arr[i]);
            }
        }
    }
    if (choice == 'D' || choice == 'd')
    {
        return 0;
    }
    return 1;
}
void convert_to_words(int num)
{
    char *ones[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    char *tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    char *hundreds[] = {"hundred"};
    A = 0, B = 0, C = 0;
    if (num == 0)
    {
        checkletters(ones[0]);
        return;
    }

    if (num >= 100)
    {
        checkletters(ones[num / 100]);
        checkletters(hundreds[0]);
        num = num % 100;
    }

    if (num >= 20)
    {
        checkletters(tens[num / 10]);
        num = num % 10;
    }

    if (num > 0)
    {
        checkletters(ones[num]);
    }

    //  printf("\n");
}

void checkletters(char word[])
{
    int i, length, j;
    length = strlen(word);
    for (i = 0; i < length; i++)
    {

        if (word[i] == 'o')
        {
            A++;
        }
        if (word[i] == 'u')
        {
            B++;
        }
        if (word[i] == 'e')
        {
            C++;
        }
    }
}