#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int rows;
    printf("Enter number of strings: ");
    scanf("%d ", &rows);

    char str[rows][100];

    for (int i = 0; i < rows; i++)
    {
        fgets(str[i], 100, stdin);
        str[i][strlen(str[i]) - 1] = '\0';
    }

    printf("\nInputs:\n\n");
    for (int i = 0; i < rows; i++)
    {
        printf("%s\n", *(str + i));
    }

    char base[50];
    strcpy(base, *str);
    int n = strlen(base);
    for (int i = 1; i < rows; i++)
    {
        int count = 1;
        while (strncmp(base, str[i], count) == 0)
        {
            count++;
        }
        count = count - 1;
        if (count < n)
        {
            n = count;
        }
    }

    char prefix[5];
    strncpy(prefix, base, n);
    printf("\nlargest prefix: \"%s\"", prefix);

    return 0;
}