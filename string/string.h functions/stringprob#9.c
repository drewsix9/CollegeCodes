#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *replace(char *str, char *sub, char *with)
{
    int str_len = strlen(str);
    char temp[str_len];
    int sub_len = strlen(sub);
    int with_len = strlen(with);

    int occurence = 0;
    int i = 0;
    int j = 0;

    char *final;

    if (sub_len == with_len)
    {
        final = malloc((str_len + 1) * sizeof(char));
    }
    else
    {
        strcpy(temp, str);
        while (strstr(temp, sub))
        {
            occurence++;
            strcpy(temp, (strstr(temp, sub)) + sub_len);
        }

        int size_to_allocate = str_len + ((with_len - sub_len) * occurence) + 1;
        final = malloc(size_to_allocate * sizeof(char));
    }

    i = 0;
    j = 0;
    while (i < str_len)
    {
        if (strstr(&str[i], sub) == &str[i])
        {
            strcpy(&final[j], with);
            i += sub_len;
            j += with_len;
        }
        else
        {
            final[j] = str[i];
            i++;
            j++;
        }
    }
    final[j] = '\0';
    return final;
}

int main()
{
    char str[100];
    char sub[50];
    char with[50];
    printf("Enter string: ");
    fgets(str, 100, stdin);
    str[strlen(str) - 1] = '\0';

    printf("Enter a substring from string: ");
    fgets(sub, 100, stdin);
    sub[strlen(sub) - 1] = '\0';

    printf("Enter a string to replace: ");
    fgets(with, 100, stdin);
    with[strlen(with) - 1] = '\0';

    replace(str, sub, with);

    printf("\nOutput: %s", replace(str, sub, with));

    return 0;
}