#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    char key[100];

    printf("Enter string: ");
    gets(str);

    printf("Enter string to be reversed: ");
    gets(key);

    int sizekey = strlen(key);
    char *ptr = strstr(str, key);
    while (ptr != NULL)
    {
        int pos = ptr - str;
        int last = pos + sizekey - 1;
        int mid = (pos + last) / 2;
        int n = 0;
        for (int i = pos; i < mid; i++)
        {
            char temp = str[i];
            str[i] = str[last - n];
            str[last - n] = temp;
            n++;
        }
        ptr = strstr(str, key);
    }

    printf("\nOutput: %s", str);
}
