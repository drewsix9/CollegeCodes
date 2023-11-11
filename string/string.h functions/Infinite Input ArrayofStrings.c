#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int size = 10;
    char **str = (char **)malloc(size * sizeof(char *));
    if (str == NULL)
        printf("\nMemory Allocation failed!\n");

    printf("Enter strings:\n");

    int n = 0;
    char buffer[50];
    while (fgets(buffer, 50, stdin) && buffer[0] != '\n')
    {
        if (n >= size - 1)
        {
            printf("\nReached maximim memory allocation. Reallocating memory...\n\n");
            size += 10;
            str = realloc(str, size * sizeof(char *));
            if (str == NULL)
                printf("\nMemory Allocation failed!\n");
        }
        str[n] = (char *)malloc(strlen(buffer) * sizeof(char));
        strcpy(str[n], buffer);
        str[n][strlen(str[n]) - 1] = '\0';
        n++;
    }

    printf("\nOutput:\n");
    for (int i = 0; i < n; i++)
    {
        printf("str[%d] = %s\n", i, str[i]);
    }

    return 0;
}