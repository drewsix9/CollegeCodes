#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse(char *str)
{
    int size = strlen(str);
    for (int i = size - 1; i >= 0; i--)
    {
        printf("%c", str[i]);
    }
    printf(" ");
}

int main()
{
    char buffer[100];
    char str[100][100];

    printf("Enter input: ");
    gets(buffer);

    char nonwords[] = " \n\0";

    int n = 0;
    char *ptr = strtok(buffer, nonwords);
    while (ptr != NULL)
    {
        // storing each word to a 2D array named str[][]
        strcpy(str[n], ptr);
        ptr = strtok(NULL, nonwords);
        n++;
    }

    int freq[n];
    memset(freq, -1, n * sizeof(int)); // setting the values of freq to -1

    for (int i = 0; i < n; i++)
    {
        int count = 1;
        for (int j = i + 1; j < n; j++)
        {
            // return value sa strcmp is either a positive, negative or zero. if zero, pasabot equal ang duha ka string
            if (strcmp(str[i], str[j]) == 0)
            {
                count++;
                // pag kita nato na naay nagkapareha, matic 0 na ilang freq
                freq[i] = 0;
                freq[j] = 0;
            }
        }
        if (freq[i] != 0)
        {
            freq[i] = count;
        }
    }

    printf("\nOutput: ");
    for (int i = 0; i < n; i++)
    {
        if (freq[i] != 0)
        {
            reverse(str[i]);
            // printf("%s ",strrev(str[i]));
            // ^^^^^
            // |||||
            // pwede ra sd ni sa pag reverse sa string
        }
        else
        {
            printf("%s ", str[i]);
        }
    }

    return 0;
}