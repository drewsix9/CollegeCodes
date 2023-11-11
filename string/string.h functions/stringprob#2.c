#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int size;
    printf("Enter number of strings: ");
    scanf("%d", &size);
    while (fflush(stdin); != '\n')
        ;

    char **str = (char **)malloc(size * sizeof(char *));
    char buffer[100];

    for (int i = 0; i < size; i++)
    {
        fgets(buffer, 100, stdin);
        str[i] = (char *)malloc(strlen(buffer) * sizeof(char));
        strcpy(str[i], buffer);
        str[i][strlen(str[i]) - 1] = '\0';
    }

    // for (int i = 0; i < size; i++)
    // {
    //     for (int j = i + 1; j < size; j++)
    //     {
    //         if (strcmp(str[i], str[j]) == 0)
    //         {
    //             str[j][0] = '\0';
    //         }
    //     }
    // }

    // REMOVE DUPLICATE
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (strcmp(str[i], str[j]) == 0)
            {
                int k = j;
                while (k < size - 1)
                {
                    strcpy(str[k], str[k + 1]);
                    k++;
                }
                str[k][0] = '\0';
                size--;
            }
        }
    }

    // int freq[size];
    // for (int i = 0; i < size; i++)
    // {
    //     freq[i] = -1;
    // }

    // for (int i = 0; i < size; i++)
    // {
    //     int count = 1;
    //     for (int j = i + 1; j < size; j++)
    //     {
    //         if (strcmp(str[i], str[j]) == 0)
    //         {
    //             count++;
    //             freq[j] = 0;
    //         }
    //     }
    //     if (freq[i] != 0)
    //     {
    //         freq[i] = count;
    //     }
    // }

    printf("\nOutput:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%s\n", str[i]);
    }

    // printf("\nFrequency Output:\n");
    // for (int i = 0; i < size; i++)
    // {
    //     if (freq[i] != 0)
    //     {
    //         printf("string \"%s\" occured %d times\n", str[i], freq[i]);
    //     }
    // }

    return 0;
}