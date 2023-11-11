#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int size;
    printf("Enter number of strings: ");
    scanf("%d", &size);
    fflush(stdin);

    char **str = (char **)malloc(size * sizeof(char *));

    char buffer[100];
    for (int i = 0; i < size; i++)
    {
        fgets(buffer, 100, stdin);
        str[i] = (char *)malloc(strlen(buffer) * sizeof(char));
        strcpy(str[i], buffer);
        str[i][strlen(str[i]) - 1] = '\0';
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (strcmp(str[i], str[j]) > 0)
            {
                char *temp;
                strcpy(temp, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], temp);
            }
        }
    }

    printf("\nSorted:\n\n");
    for (int i = 0; i < size; i++)
    {
        printf("%s\n", str[i]);
    }
    return 0;
}