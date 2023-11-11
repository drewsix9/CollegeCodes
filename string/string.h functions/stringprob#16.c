/*Write a program that takes in a string of words separated by spaces. The program should output in reverse the word that has a prime number of unique characters.
Example:
Input: "hello world hoord hehez"
Output: "hello dlrow hoord zeheh"
Explanation: "world" has a prime number of unique characters (5), and "hehez" has a prime number of unique characters (3)
*/

#include <stdio.h>
#include <string.h>

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

int isPrime(int num)
{
    if (num == 1)
        return 0;

    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
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
        int count = CountUnique(word);
        if (isPrime(count))
        {
            printf("%s ", strrev(word));
        }
        else
        {
            printf("%s ", word);
        }
        word = strtok(NULL, " ");
    }
}