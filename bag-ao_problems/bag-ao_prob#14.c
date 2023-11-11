#include <stdio.h>
#include <string.h>

int main()
{
    int size;
    printf("Enter number of strings: ");
    scanf("%d", &size);
    fflush(stdin);
    // flushes the standard input stream so that no '\n' will be in the next user input.
    char str[size][100];

    for (int i = 0; i < size; i++)
    {
        printf("Enter string%d: ", i + 1);
        fgets(str[i], 100, stdin);         // fgets function takes in the strings from user input until user inputs a newline character ('\n').
        str[i][strlen(str[i]) - 1] = '\0'; // fgets stores the string as well as the newline character, thus it is necessary to add a null terminator at the end of string.
    }

    char sub[100];
    printf("\nEnter substring: ");
    fgets(sub, 100, stdin);
    sub[strlen(sub) - 1] = '\0';

    for (int i = 0; i < size; i++)
    {
        if (strstr(str[i], sub)) // strstr() returns a pointer to the found substring in str[i], if it cannot find the substring, it will return 0
        {
            printf("\nThe substring '%s' was found in string '%s' at index: %lld\n", sub, str[i], strstr(str[i], sub) - str[i]);
        }
        else
        {
            printf("\nThe substring '%s' was NOT found in string '%s'\n", sub, str[i]);
        }
    }

    return 0;
}