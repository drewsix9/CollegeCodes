// Kung prime number ang number of letters the word kwa a nang vowels otherwise kwa a ang consonants

#include <string.h>
#include <stdio.h>

int isPrime(int num)
{
    if (num <= 1)
    {
        return 0;
    }

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
    char str[100];
    char vowels[] = "aeiouAEIOU";
    printf("Enter string: ");
    gets(str);

    char *word = strtok(str, " ");
    while (word != NULL)
    {
        int size = strlen(word);
        if (isPrime(size))
        {
            // takeout vowels
            for (int i = 0; i < size; i++)
            {
                if (!strchr(vowels, word[i]))
                {
                    printf("%c", word[i]);
                }
            }
            printf(" ");
        }
        else
        {
            // takeout consonants
            for (int i = 0; i < size; i++)
            {
                if (strchr(vowels, word[i]))
                {
                    printf("%c", word[i]);
                }
            }
            printf(" ");
        }

        word = strtok(NULL, " ");
    }
    return 0;
}