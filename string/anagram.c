#include <stdio.h>
#include <string.h>

int isAnagram(char *str1, char *str2)
{
    if (strlen(str1) != strlen(str2))
        return 0;
    int i = 0;
    int size = strlen(str1);

    while (i < size)
    {
        if (strchr(str2, str1[i]) == NULL)
        {
            return 0;
        }
        i++;
    }

    return 1;
}

int main()
{
    char str1[50], str2[50];
    while (1)
    {
        printf("Enter string1: ");
        scanf("%s", str1);
        printf("Enter string2: ");
        scanf("%s", str2);

        if (isAnagram(str1, str2))
        {
            printf("\n\"%s\" and \"%s\" ANAGRAMS!\n", str1, str2);
        }
        else
        {
            printf("\nNOT ANAGRAMS!\n");
        }
    }

    return 0;
}