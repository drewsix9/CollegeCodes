#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int rows;
    printf("Enter number of strings: ");
    scanf("%d", &rows);
    fflush(stdin);

    char str[rows][100];

    for (int i = 0; i < rows; i++)
    {
        fgets(str[i], 100, stdin);
        str[i][strlen(str[i]) - 1] = '\0';
    }

    char prefix[50];

    strcpy(prefix, *str);

    // for (int i = 1; i < rows; i++)
    // {
    //     int j = 0;
    //     while (prefix[j] != '\0' && str[i][j] != '\0' && prefix[j] == str[i][j])
    //     {
    //         j++;
    //     }
    //     prefix[j] = '\0';
    // }

    for (int i = 1; i < rows; i++)
    {
        while (strncmp(prefix, str[i], strlen(prefix)) != 0)
        {
            prefix[strlen(prefix) - 1] = '\0';
        }
    }

    if (strlen(prefix) > 0)
    {
        printf("\nThe longest common prefix: \"%s\"", prefix);
    }
    else
    {
        printf("\nNo common prefix!");
    }

    return 0;
}
