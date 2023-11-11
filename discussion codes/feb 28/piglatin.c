#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Words starting with vowel letter e add og "ay"
// Words starting with constant letter, e pa last tung first letter then add "ay"

// word if = printable space printable
// if length of word is prime piglatin

int main()
{
    char str[100];
    printf("Enter string: ");
    gets(str);
    int size = strlen(str) - 1;

    for (int i = 0; i <= size; i++)
    {
        int count = 0;
        for (int j = 0; j <= size; j++) // counts the size of word
        {
            if (str[j] != ' ')
            {
                count++;
                i++;
            }
        }
        int pos = count - 1; // index of last character

        int factor = 0;
        for (int k = 2; k < count; k++) // check if count isPrime
        {
            if (count % k == 0)
            {
                factor++;
                break;
            }
        }
        if (factor == 0)
        {
            // check if vowel or consonant
            if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
            {
                str[pos + 1] = 'a';
                str[pos + 2] = 'y';
            }
            else
            {
                char temp = str[i];
                for (int l = i + 1; l <= size; l++)
                {
                    str[l - 1] = str[l];
                }
                str[size] = temp;
                str[size + 1] = 'a';
                str[size + 2] = 'y';
            }
        }
    }
    str[strlen(str)] = '\0';

    printf("\n%s", str);
    return 0;
}