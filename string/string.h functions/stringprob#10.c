#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char str[100][100];

    printf("Enter strings:\n");

    char buffer[20];
    int n = 0;
    while (fgets(buffer, 20, stdin) != NULL && buffer[0] != '\n')
    {
        strcpy(str[n], buffer);
        str[n][strlen(str[n]) - 1] = '\0';
        n++;
    }

    char sub[20];
    printf("\nEnter substring to find: ");
    fgets(sub, 20, stdin);
    sub[strlen(sub) - 1] = '\0';

    int freq[n];
    memset(freq, 0, n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        int count = 0;
        char temp[strlen(str[i])];
        strcpy(temp, str[i]);
        while (strstr(temp, sub) != NULL)
        {
            count++;
            strcpy(temp, strstr(temp, sub) + 1);
        }
        freq[i] = count;
    }

    printf("\nOutput: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", freq[i]);
    }

    return 0;
}