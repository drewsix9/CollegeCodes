/*
    Enter a string with letters, numbers and symbols. Remove all other characters aside from letters. Sort the letters in lexicographical order

    p2'r-o@gram84iz./
    = programiz
    = agimoprrz
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int i, j;
    char str[100];
    printf("Enter string: ");
    gets(str);

    char letter[100];
    int n = 0;

    for (i = 0; i < strlen(str); i++)
    {
        if (isalpha(str[i]))
        {
            letter[n++] = str[i];
        }
    }

    printf("\nOutput string 1: ");
    puts(letter);

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (letter[i] > letter[j])
            {
                char temp = letter[i];
                letter[i] = letter[j];
                letter[j] = temp;
            }
        }
    }

    printf("\nOutput string 2: ");
    puts(letter);

    return 0;
}