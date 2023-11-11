#include <stdio.h>
#include <string.h>

int main()
{
    while (1)
    {
        char allowed[] = "abcdefghijklmnopqrtstuvwxyz";

        char str[100];
        printf("\nEnter password: ");
        gets(str);

        // hell0oworld_123

        int len = strspn(str, allowed);

        printf("\nlen = %d", len);

        if (len == strlen(str))
        {
            printf("\nPassword is allowed!");
        }
        else
        {
            printf("\nPassword NOT allowed!");
        }
    }

    return 0;
}
