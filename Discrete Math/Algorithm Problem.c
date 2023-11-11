// Alphabetically arrange words

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    while (1)
    {
        char buffer[100];
        char str[100][100];
        printf("\nEnter words: ");
        fgets(buffer, 100, stdin);
        buffer[strlen(buffer) - 1] = '\0';

        int n = 0;
        char *ptr = strtok(buffer, ", \n\t\0");
        while (ptr != NULL)
        {
            strcpy(str[n++], ptr);
            ptr = strtok(NULL, " \n\t\0");
        }

        char temp[20];
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (strcmp(str[i], str[j]) > 0)
                {
                    strcpy(temp, str[i]);
                    strcpy(str[i], str[j]);
                    strcpy(str[j], temp);
                }
            }
        }

        printf("\nOutput: ");
        for (int i = 0; i < n; i++)
        {
            printf("%s ", str[i]);
        }
        printf("\n\nPress any key to continue... ");
        getch();
        system("cls");
    }

    return 0;
}