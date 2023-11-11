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

    printf("\nInputs:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%s\n", str[i]);
    }

    char suffix[50];
    strcpy(suffix, str[0]);

    for (int i = 1; i < size; i++)
    {
        int j = 0;
        while (strstr(str[i], suffix) == NULL)
        {
            strcpy(suffix, &suffix[1]);
        }
    }

    printf("\nlongest common suffix: %s\n", suffix);

    return 0;
}
