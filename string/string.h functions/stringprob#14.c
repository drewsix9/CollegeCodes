// Write a program that takes in a string of words separated by spaces. The program should output the longest word in the string that contains at least one repeated letter. If there are multiple words with the same length that meet this criteria, output the first one that appears in the string.

// Input: "hello world hoord"
// Output: "hello"
// Explanation: "hello" is the longest word in the string that contains at least one repeated letter ("l" appears twice).

#include <stdio.h>
#include <string.h>

int hasRepeatingLetter(char *word)
{

    for (int i = 0; i < strlen(word); i++)
    {
        if (strchr(word + i + 1, word[i]))
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    char str[100], max_str[100];
    printf("Enter string: ");
    gets(str);

    int hasRepeating = 0;
    char *word = strtok(str, " ");
    while (word != NULL)
    {
        // Check if it has atleast one repeating letter;
        if (hasRepeatingLetter(word))
        {
            hasRepeating = 1;
            if (strlen(max_str) < strlen(word))
            {
                strcpy(max_str, word);
            }
        }
        word = strtok(NULL, " ");
    }

    if (hasRepeating == 1)
    {
        printf("\nOutput: %s", max_str);
    }
    else
    {
        printf("\nThere is no word that contains at least one repeated letter!");
    }
}