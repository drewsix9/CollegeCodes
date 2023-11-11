/*
    abb bab bba
    yes  yes  no

    check palindorome, ignore vowels from the left
*/
#include <string.h>
#include <stdio.h>

int isPalindrome(char *str)
{
    for (int i = 0; i < strlen(str) / 2; i++)
    {
        if (str[i] != str[strlen(str) - i - 1])
        {
            return 0;
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
        int size = word;
        int pos = strspn(word, "aeiouAEIOU");
        if (isPalindrome(word + pos))
        {
            printf("%s ", word);
        }
        word = strtok(NULL, " ");
    }
}