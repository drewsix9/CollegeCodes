#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

// The program lets the user input a string of words then prints the words in alphabetical order

int main()
{
    char str[MAX];
    int pos_1stletter[MAX];
    int CountofEachWord[MAX];
    char LetterstoSort[MAX];
    printf("Enter string of words: ");
    gets(str);
    // printf("\nOutput: ");
    int size = strlen(str) - 1;

    int n = 0;
    // finding the index of each 1st letter // finding the count of each letter // finding the letters to sort
    for (int i = 0; i <= size; i++)
    {
        pos_1stletter[n] = i;
        LetterstoSort[n] = str[i];
        int j = i;
        int count = 0;
        while (j <= size && str[j] != ' ')
        {
            count++;
            j++;
        }
        CountofEachWord[n] = count;
        i = j;
        n++;
    }

    // sorting LetterstoSort[] and other variables
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (LetterstoSort[i] > LetterstoSort[j])
            {
                char temp = LetterstoSort[i];
                LetterstoSort[i] = LetterstoSort[j];
                LetterstoSort[j] = temp;

                temp = CountofEachWord[i];
                CountofEachWord[i] = CountofEachWord[j];
                CountofEachWord[j] = temp;

                temp = pos_1stletter[i];
                pos_1stletter[i] = pos_1stletter[j];
                pos_1stletter[j] = temp;
            }
        }
    }

    // printing of sorted words
    printf("\nOutput: ");
    for (int i = 0; i < n; i++)
    {
        int j = pos_1stletter[i];
        while (j < CountofEachWord[i] + pos_1stletter[i])
        {
            printf("%c", str[j]);
            j++;
        }
        printf(" ");
    }

    return 0;
}
