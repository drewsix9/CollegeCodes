/*
Enter a string, print the words only if it is palindrome when the second half are swapped

bobo- boob - print
labla - labal - print
hala - haal - do not print
*/


#include <stdio.h>
#include <string.h>

int checker(char *str)
{
    int size = strlen(str);
    int mid = size / 2;
    if (size == 2)
    {
        return 1;
    }

    if (size % 2 == 0)
    {
        for (int i = 0; i < mid; i++)
        {
            if (str[i] != str[mid + i])
            {
                return 0;
            }
        }
    }
    else
    {
        mid += 1;
        for (int i = 0; i < mid - 1; i++)
        {
            if (str[i] != str[mid + i])
            {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    char str[100];
    printf("Enter string: ");
    gets(str);

    printf("\nOutput: ");
    char *word = strtok(str, " ");
    while (word != NULL)
    {
        if (checker(word))
        {
            printf("%s ", word);
        }
        word = strtok(NULL, " ");
    }
    return 0;
}