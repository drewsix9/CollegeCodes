#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[100];
    printf("Enter inputs: ");
    gets(str);

    printf("\nOutput: ");
    char *ptr = strtok(str, " ");
    while (ptr != NULL)
    {
        char *point = strchr(ptr, '.');
        if (point)
        {
            int i = 0;
            while (ptr[i] != '.')
            {
                printf("%c", ptr[i]);
                i++;
            }
            printf(".");
            char *ptr2 = point + 1;
            strrev(ptr2);
            printf("%s ", ptr2);
        }
        else
        {
            printf("%s ", ptr);
        }

        ptr = strtok(NULL, " ");
    }

    return 0;
}