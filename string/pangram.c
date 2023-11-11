#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char str[256];
    printf("Enter string: ");
    fgets(str, 256, stdin);
    str[strlen(str) - 1] = '\0';

    int size = strlen(str);

    int freq[26];
    for (int i = 0; i < 26; i++)
        freq[i] = 0;

    for (int i = 0; i < size; i++)
    {
        if (isalpha(str[i]))
        {
            char temp = tolower(str[i]);
            freq[temp - 'a']++;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        if (freq[i] == 0)
        {
            printf("\n\'%s\' is a NOT a PANGRAM", str);
            return 0;
        }
    }

    printf("\n\'%s\' is a a PANGRAM", str);

    return 0;
}
