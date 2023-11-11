#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 100

// the program takes in a string of words, if the word has prime total number of letters, convert to piglatin.

int isPrime(int num)
{
    if (num <= 1)
        return 0;

    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    char str[100], vowels[] = "aeiouAEIOU";
    printf("Enter strings: ");
    gets(str);

    char *word = strtok(str, " ");
    while (word != NULL)
    {
        if (isPrime(strlen(word)) == 1)
        {
            if (strchr(vowels, word[0]))
            {
                printf("%s", word);
                printf("ay ");
            }
            else
            {
                printf("%s", word + 1);
                printf("%c", word[0]);
                printf("ay ");
            }
        }
        else
        {
            printf("%s ", word);
        }
        word = strtok(NULL, " ");
    }

    return 0;
}