/*Write a program that takes in a string of words separated by spaces. The program should output the word that has the highest number of unique characters. If there are multiple words with the same number of unique characters, output the first one that appears in the string.
Example:
Input: "hello world hoord"
Output: "world"
Explanation: "world" has the highest number of unique characters (5), while "hello" and "hoord" both have 4 unique characters.*/

#include <string.h>
#include <stdio.h>

int CountUnique(char *word)
{
    int unique = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        if (!strchr(word + i + 1, word[i]))
        {
            unique++;
        }
    }
    return unique;
}

int main()
{
    char str[100], max[100];
    printf("Enter string: ");
    gets(str);

    char *word = strtok(str, " ");
    while (word != NULL)
    {
        int count = CountUnique(word);
        printf("%d ", count);
        word = strtok(NULL, " ");
    }

    return 0;
}