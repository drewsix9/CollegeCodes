#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fptr;

    fptr = fopen("input.txt", "r");
    if (fptr == NULL)
    {
        printf("Error!");
        return 1;
    }

    // fputs("Hello!!", fptr);

    int n = 0;
    char str[100][100];
    while (fgets(str[n], 100, fptr) != NULL)
    {
        str[n][strlen(str[n]) - 1] = '\0';
        n++;
    }

    FILE *fptr2;
    fptr2 = fopen("text2.txt", "w");
    if (fptr2 == NULL)
    {
        printf("Error!");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        fprintf(fptr2, strrev(str[i]));
        fprintf(fptr2, "\n");
    }

    fclose(fptr);
    fclose(fptr2);
    return 0;
}