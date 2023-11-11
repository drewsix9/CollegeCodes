// Words starting with vowel letter e add og "ay"
// Words starting with constant letter, e pa last tung first letter then add "ay"

// ear = earay
// dan = anday

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isVowel(char *str)
{
    char *vowels = "aeiouAEIOU";
    if (strchr(vowels, *str))
    {
        return 1;
    }

    return 0;
}

int main()
{
    int total = 0;
    printf("Enter how many strings: ");
    scanf("%d", &total);
    fflush(stdin);;

    char **str = calloc(total, sizeof(char *));

    char buffer[100];
    int size;

    for (int i = 0; i < total; i++)
    {
        fgets(buffer, 100, stdin);
        size = strlen(buffer);
        buffer[size - 1] = '\0';
        str[i] = malloc(size * sizeof(char));
        strcpy(str[i], buffer);
    }

    printf("\nPiglatin:\n\n");
    for (int i = 0; i < total; i++)
    {
        if (isVowel(str[i]) == 1)
        {
            strcat(str[i], "ay");
            printf("%s\n", str[i]);
        }
        else
        {
            char temp[50];
            strcpy(temp, str[i] + 1);
            strncat(temp, str[i], 1);
            strcat(temp, "ay");
            temp[strlen(temp)] = '\0';
            printf("%s\n", temp);
        }
    }
}