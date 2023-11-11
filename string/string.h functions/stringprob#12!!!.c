#include <stdio.h>
#include <string.h>

int main()
{
    char str[50];
    printf("Enter string: ");
    fgets(str, 50, stdin);
    str[strlen(str) - 1] = '\0';

    int size = strlen(str);
    char temp[size], longest[size];
    int max = 0;
    char *ptr;

    for (int i = 0; i < size; i++)
    {
        temp[0] = '\0';
        int j = i + 1;
        int count = 1;
        strncpy(temp, str + j, count);
        while (j < size && (strchr(temp, str[i])) == NULL)
        {
            count++;
            strncpy(temp, str + j, count);
        }
        if (max < count)
        {
            max = count;
            strncpy(longest, str + i, 1);
            strncat(longest, temp, max - 1);
            i = count - i - 1;
        }
    }

    printf("longest substring w/o repeated characters is: %s", longest);

    return 0;
}