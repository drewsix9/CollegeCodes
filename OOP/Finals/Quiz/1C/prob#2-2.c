#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*

input: hello world orleans
string to be reversed: orl

output: hello wlrod lroeans

hello world orleans

*/

int main()
{
    char str[100];
    char key[100];

    printf("Enter string: ");
    gets(str);

    printf("Enter string to be reversed: ");
    gets(key);

    int size = strlen(key);

    char *ptr = str;
    for (;;)
    {
        if (ptr[0] == '\0')
            break;

        if (strncmp(ptr, key, size) == 0)
        {
            char temp[50];
            strncpy(temp, key, size);
            printf("%s", strrev(temp));
            ptr += size;
        }
        else
        {
            printf("%c", ptr[0]);
            ptr += 1;
        }
    }

    return 0;
}
