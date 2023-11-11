#include <stdio.h>
#include <string.h>

int main()
{
    char str[100], key[100];
    printf("Enter input: ");
    gets(str);

    printf("\nEnter word to remove: ");
    gets(key);
    int size = strlen(key);
    int i = 0;
    char temp[100];

    printf("\nOutput: ");
    while (i < strlen(str))
    {
        strncpy(temp, str + i, size);
        if (strncmp(temp, key, size) == 0)
        {
            i += size - 1;
        }
        else
        {
            printf("%c", temp[0]);
        }
        i++;
    }

    return 0;
}