#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int total = 0;
    printf("Enter how many strings: ");
    scanf("%d", &total);
    fflush(stdin);;

    char **str = malloc(total * sizeof(char *));

    char buffer[100];
    int size;

    for (int i = 0; i < total; i++)
    {
        fgets(buffer, 100, stdin);
        size = strlen(buffer);
        buffer[size - 1] = '\0';
        str[i] = malloc(size * sizeof(char));
        strcpy(str[i], buffer);
    }

    printf("\nInput:\n");
    for (int i = 0; i < total; i++)
    {
        printf("%s\n", str[i]);
    }
}