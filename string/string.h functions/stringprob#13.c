/*
Input: hello world order horde
Substring to be found: or
Output:
Substring found at word 2, index: 7
Substring found at word 3, index: 12
Substring found at word 4, index: 19
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char str[100], key[50];
    printf("Enter string: ");
    gets(str);
    printf("\nEnter string to search: ");
    gets(key);

    char *ptr = strtok(str, " ");
    int wordcount = 0;
    printf("\nOutput:\n");

    while (ptr != NULL)
    {
        wordcount++;
        char *point = strstr(ptr, key);
        if (point != NULL)
        {
            printf("substring found at word %d, index: %d\n", wordcount, point - str);
        }
        ptr = strtok(NULL, " ");
    }

    return 0;
}