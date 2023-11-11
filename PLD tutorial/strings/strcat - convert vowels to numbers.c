#include <stdio.h>
#include <string.h>

void conversion(char *str)
{
    int size = strlen(str);
    for (int i = 0; i < size; i++)
    {
        if (str[i] == 'a' || str[i] == 'A')
            str[i] = '1';
        else if (str[i] == 'e' || str[i] == 'E')
            str[i] = '2';
        else if (str[i] == 'i' || str[i] == 'I')
            str[i] = '3';
        else if (str[i] == 'o' || str[i] == 'O')
            str[i] = '4';
        else if (str[i] == 'u' || str[i] == 'u')
            str[i] = '5';
    }
}

int main()
{
    char str1[100];
    printf("Enter string1: ");
    fgets(str1, 100, stdin);
    str1[strlen(str1) - 1] = '\0';

    char str2[100];
    printf("Enter string2: ");
    fgets(str2, 100, stdin);
    str2[strlen(str2) - 1] = '\0';

    strcat(str1, str2);
    char const_vowels[] = "aeiouAEIOU";

    char consonants[100];
    char vowels[100];
    int size = strlen(str1);
    int conso_n = 0;
    int vowel_n = 0;
    for (int i = 0; i < size; i++)
    {
        if (strchr(const_vowels, str1[i]) == NULL)
        {
            consonants[conso_n++] = str1[i];
        }
        else
        {
            vowels[vowel_n++] = str1[i];
        }
    }
    consonants[conso_n++] = '\0';
    vowels[vowel_n++] = '\0';

    conversion(vowels);

    strcat(consonants, vowels);

    printf("\nOutput: ");
    puts(consonants);

    return 0;
}

/*
    a-1
    e-2
    i-3
    o-4
    u-5
*/