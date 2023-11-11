#include <stdio.h>
#include <string.h>

char FindCommon(char str[][100], int n)
{
    for (int i = 0; i < n; i++)
    {
        char temp;
        for (int j = 0; j < strlen(str[i]); j++)
        {
            temp = str[i][j];
            int isFound = 1;
            for (int k = 0; k < n; k++)
            {
                if ((strchr(str[k], temp)) == NULL)
                {
                    isFound = 0;
                    break;
                }
            }
            if (isFound == 1)
            {
                return temp;
            }
        }
    }
    return '\0';
}

int main()
{
    char str[100][100];
    printf("Enter strings:\n");

    int n = 0;
    char buffer[50];
    while (fgets(buffer, 50, stdin) && buffer[0] != '\n')
    {
        strcpy(str[n], buffer);
        str[n][strlen(str[n]) - 1] = '\0';
        n++;
    }

    char delimiter = FindCommon(str, n);
    if (delimiter == '\0')
    {
        printf("\nThere is no common letter!\n");
    }
    else
    {
        printf("\nCommon letter: %c\n", delimiter);
        printf("\nOutput:\n");

        for (int i = 0; i < n; i++)
        {
            char delim[5];
            delim[0] = delimiter;
            delim[1] = '\0';

            char *token = NULL;
            token = strtok(str[i], delim);
            while (token)
            {
                printf("%s", token);
                token = strtok(NULL, delim);
            }
            printf("\n");
        }
    }

    return 0;
}