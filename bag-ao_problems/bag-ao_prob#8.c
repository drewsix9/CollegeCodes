#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[100];
    printf("Enter string of words: ");
    gets(str);
    int size = strlen(str);

    // finding the pos of first letters
    for (int i = 0; i < size; i++)
    {
        // pos_1stletter[n++] = i;
        int count = 0;
        int remove_count = 0;
        int j = i;
        while (j < size && str[j] != ' ')
        {
            count++;
            j++;
        }

        if (count > 0)
        {

            for (int k = i; k < count + i; k++)
            {
                for (int l = k + 1; l < count + i;)
                {
                    if (str[k] == str[l])
                    {
                        remove_count = remove_count + 1;
                        printf("\nFound a duplicate of '%c'\n", str[l]);
                        for (int m = l; m < size; m++)
                        {
                            str[m] = str[m + 1];
                        }
                        size--;
                    }
                    else
                    {
                        l++;
                    }
                }
            }
        }

        i = j - remove_count;
    }

    printf("\nOutput: ");
    puts(str);

    return 0;
}