#include <stdio.h>
#include <string.h>

/*
    aloha -> alaho
*/

int main()
{
    char str[100], vowels[] = "aeiouAEIOU"; // gamiton para reference inig strchr
    int pos[100], n = 0;
    printf("Enter string: ");
    gets(str);

    int size = strlen(str);
    for (int i = 0; i < size; i++)
    {
        // strchr(vowels, str[i]) is mu check if str[i] is present sa 'vowels' na string, if dile siya present, mu return siya ug NULL pointer
        if (strchr(vowels, str[i]) != NULL)
        {
            // gi store ang index sa vowel nato
            pos[n++] = i;
        }
    }

    // bubble sort sa vowels with respect to their positions
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (str[pos[i]] > str[pos[j]])
            {
                char temp = str[pos[i]];
                str[pos[i]] = str[pos[j]];
                str[pos[j]] = temp;
            }
        }
    }
    // output str
    puts(str);

    return 0;
}