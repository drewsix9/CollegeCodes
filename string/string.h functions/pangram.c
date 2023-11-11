#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char str[256];
    printf("Enter string: ");
    gets(str);

    int size = strlen(str);
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < 26; i++)
    {
        if (!strchr(str, alphabet[i]))
        {
            printf("\n\'%s\' is NOT a PANGRAM", str);
            return 0;
        }
    }

    printf("\n\'%s\' is a PANGRAM", str);

    return 0;
}
