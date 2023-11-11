/*
enter string of inputs:
alphaay alpha bravo ravobay

output:
alpha ahpla ovarb bravo

ma convert to normal ang piglatin
ma reverse ang word if normal
*/

#include <string.h>
#include <stdio.h>

int isPiglatin(char *word)
{
    int size = strlen(word);
    if (word[size - 1] != 'y' && word[size - 2] != 'a')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int main()
{
    char str[100], vowels[] = "aeiouAEIOU";
    printf("Enter string: ");
    gets(str);

    printf("\nOutput: ");
    char *word = strtok(str, " ");
    while (word != NULL)
    {
        if (isPiglatin(word) == 1)
        {
            // is piglatin
            int size = strlen(word);
            char *ptr = strchr(vowels, word[size - 3]);
            if (ptr != NULL)
            {
                // piglatin vowel condition
                //  alphaay
                //  alpha
                word[size - 3 + 1] = '\0';
                printf("%s ", word);
            }
            else
            {
                // piglatin consonant condition
                //  ravobay
                //  bravo
                printf("%c", word[size - 3]);
                word[size - 3] = '\0';
                printf("%s ", word);
            }
        }
        else
        {
            // not piglatin
            strrev(word);
            printf("%s ", word);
        }
        word = strtok(NULL, " ");
    }

    return 0;
}