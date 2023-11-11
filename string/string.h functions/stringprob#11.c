#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char str[100];
    printf("Enter string: ");
    fgets(str, 100, stdin);
    str[strlen(str) - 1] = '\0';

    int length = strlen(str);
    int count = 0;
    int max = 0;
    char max_word[50];

    char not_word[] = " .,?!\n\t";

    int i = 0;
    while (i < length)
    {
        count = 0;
        char *ptr = &str[i];
        while (strchr(not_word, str[i]) == NULL) // Cannot see
        {
            i++;
            count++;
        }

        while (strchr(not_word, str[i]) != NULL)
        {
            i++;
        }

        if (max < count)
        {
            max = count;
            strncpy(max_word, ptr, count);
            // printf("\n%s", ptr);
            // printf("\nstrlen of max_word: %d", strlen(max_word));
        }
        max_word[strlen(max_word)] = '\0';
    }

    printf("\nOutput: %s", max_word);

    return 0;
}