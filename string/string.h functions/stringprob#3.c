#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    // for (int i = 0; i < size; i++)
    // {
    //     for (int j = i + 1; j < size; j++)
    //     {
    //         if (strcmp(str[i], str[j]))
    //     }
    // }
    char suffix[50];
    char compare[50];
    strcpy(suffix, str[0]);

    for (int i = 1; i < size; i++)
    {
        int j = 0;
        strcpy(compare, str[i]);
        while (strcmp(suffix, &(compare[j])))
        {
            j++;
        }
        strcpy(suffix, &(compare[j]));
    }

    if (strlen(suffix) > 0)
    {
        printf("\nlongest common suffix: %s\n", suffix);
    }
    else
    {
        printf("\nNo common suffix!\n");
    }

    return 0;
}