// Words starting with vowel letter e add og "ay"
// Words starting with constant letter, e pa last tung first letter then add "ay"

// ear = earay
// dan = anday

#include <stdio.h>
#include <string.h>

int isStartingVowel(char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return 1;
    else
    {
        return 0;
    }
}

void Vowel(char *c)
{
    char final[50] = "ay";
    strcat(c, final);
    puts(c);
}

void Conso(char *c)
{
    int size = strlen(c);
    char final[50] = "ay";

    char temp;
    temp = c[0];
    for (int i = 0; i < size - 1; i++)
    {
        c[i] = c[i + 1];
    }
    c[size - 1] = temp;

    strcat(c, final);
    puts(c);
}

int main()
{
    int rows;
    printf("Enter number of strings: ");
    scanf("%d", &rows);
    fflush(stdin);;

    char words[rows][50];

    for (int i = 0; i < rows; i++)
    {
        gets(words[i]);
    }

    printf("\nOutput:\n");
    for (int i = 0; i < rows; i++)
    {
        if ((isStartingVowel(words[i][0])) == 1)
        {
            Vowel(words[i]);
        }
        else if ((isStartingVowel(words[i][0])) == 0)
        {
            Conso(words[i]);
        }
    }
    return 0;
}