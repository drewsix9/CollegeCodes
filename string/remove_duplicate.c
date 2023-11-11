#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void remove_duplicate(char str[])
{
    int size = strlen(str);

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size;)
        {
            if (str[i] == str[j])
            {
                for (int k = j; k < size; k++)
                {
                    str[k] = str[k + 1];
                }
                size--;
            }
            else
            {
                j++; // only increments j there is no duplicate found
            }
        }
    }
}

int main()
{
    char str[100];
    gets(str);
    printf("\nOutput: ");
    remove_duplicate(str);
    puts(str);
    return 0;
}