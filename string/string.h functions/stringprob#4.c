#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int size;
    printf("Enter number of strings: ");
    scanf("%d", &size);
    while (fflush(stdin); != '\n')
        ;
    char **str = (char **)malloc(size * sizeof(char *));

    char buffer[100];
    for (int i = 0; i < size; i++)
    {
        fgets(buffer, 100, stdin);
        str[i] = (char *)malloc(strlen(buffer) * sizeof(char));
        strcpy(str[i], buffer);
        str[i][strlen(str[i]) - 1] = '\0';
    }

    int LargVowel = 0;
    char Vowel[50];
    for (int i = 0; i < size; i++)
    {
        int CountVowel = 0;
        char temp[50];
        strcpy(temp, str[i]);

        while (1)
        {
            char *ptr = strpbrk(temp, "aeiouAEIOU");
            if (ptr != NULL)
            {
                CountVowel++;
                strcpy(temp, ptr + 1);
            }
            if (ptr == NULL)
            {
                break;
            }
        }
        if (CountVowel > LargVowel)
        {
            LargVowel = CountVowel;
            strcpy(Vowel, str[i]);
        }
    }

    printf("\n\nThe string with the most vowels is \"%s\" and has a vowel count of %d\n", Vowel, LargVowel);

    return 0;
}


