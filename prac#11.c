// Write a C program that reads in a word from the user and determines whether or not the word is a palindrome.
// A palindrome is a word that is spelled the same way forwards and backwards, such as "racecar" or "level".

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isPalindrome(char[]);

int main()
{
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    if (isPalindrome(str))
    {
        printf("%s is a PALINDROME.", str);
    }
    else
    {
        printf("%s is NOT a PALINDROME.", str);
    }
}

bool isPalindrome(char str[])
{
    int length = strlen(str);
    for (int i = 0; i < length; i++)
    {
        if (str[i] != str[length - i - 1])
        {
            return false;
        }
    }
    return true;
}