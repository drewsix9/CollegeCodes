#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[100];
    char last[100];
    int pos_1st[100];
    int n = 0;
    printf("Enter string of words: ");
    gets(str);
    int size = strlen(str);

    for (int i = 0; i < size; i++)
    {
        int j = i;
        pos_1st[n] = j;
        while (j < size && str[j] != ' ')
        {
            j++;
        }
        last[n] = str[j - 1];
        i = j;
        n++;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (last[i] > last[j])
            {
                int temp = last[i];
                last[i] = last[j];
                last[j] = temp;

                temp = pos_1st[i];
                pos_1st[i] = pos_1st[j];
                pos_1st[j] = temp;
            }
        }
    }

    puts(str);

    for (int i = 0; i < n; i++)
    {
        int j = pos_1st[i];
        while (str[j] != ' ')
        {
            printf("%c", str[j]);
            j++;
        }
        printf(" ");
    }

    // printf("\n");
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ", pos_1st[i]);
    //     printf("%c ", last[i]);
    // }

    return 0;
}