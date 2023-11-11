#include <stdio.h>
#include <string.h>

int main()
{
    int rows;
    printf("Enter how many strings: ");
    scanf("%d", &rows);
    fflush(stdin);; // flushes the '\n' from the standard input after the scanf().

    char str[rows][100];

    for (int i = 0; i < rows; i++)
    {
        fgets(str[i], 100, stdin);         // fgets function takes in the strings from user input until user inputs a newline character ('\n').
        str[i][strlen(str[i]) - 1] = '\0'; // fgets stores the string as well as the newline character, thus it is necessary to add a null terminator at the end of string.
    }

    printf("\nInputs:\n\n");
    for (int i = 0; i < rows; i++)
    {
        printf("%s\n", str[i]);
    }
}