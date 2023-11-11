#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

int main()
{
    char buffer[SIZE];
    fgets(buffer, SIZE, stdin);
    char *str = malloc(strlen(buffer) * sizeof(char));
    strcpy(str, buffer);

    const char *const_str = str;

    fgets(buffer, SIZE, stdin);
    char *to_find = malloc(strlen(buffer) * sizeof(char));
    strcpy(to_find, buffer);
    // Remove newline character from to_find
    to_find[strcspn(to_find, "\n")] = '\0';

    char *result = strstr(str, to_find);

    // if (result)
    // {
    //     printf("Word is found!\n");
    //     printf("at index: %llu!\n", result - str);
    // }

    // FINDING THE 2ND OCCURENCE
    int count = 0, pos;
    do
    {
        count++;
        printf("result address = %llu and the value %c\n", result - const_str, *result);

        if (count == 2)
        {
            pos = result - const_str;
        }
        result = strstr(result + 1, to_find);

    } while (result != NULL || count < 2);

    printf("Second occurence of the word is at index: %d", pos);

    return 0;
}