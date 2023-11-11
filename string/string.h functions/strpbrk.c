#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[] = "hello world";
    char vowel[] = "aeiouAEIOU";

    char *ptr = strpbrk(str, vowel);

    if (ptr != NULL)
    {
        printf("First vowel in the string is: %c", ptr[0]);
    }
    else
    {
        printf("No vowel found in the string.");
    }

    printf("\n");
    puts(ptr);

    return 0;
}
