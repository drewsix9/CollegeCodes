#include <stdio.h>
#include <string.h>

int main()
{
    char str[100][100];
    printf("Enter strings:\n");
    int n = 0;
    char buffer[50];
    while ((fgets(buffer, 50, stdin) != NULL) && buffer[0] != '\n')
    {
        strcpy(str[n], buffer);
        str[n][strlen(str[n]) - 1] = '\0';
        n++;
    }

    int largestCount = 0;
    char largestString[50];
    for (int i = 0; i < n; i++)
    {
        char temp[50];
        strcpy(temp, str[i]);

        int count = 0;
        char *ptr = strtok(temp, " ");
        while (ptr != NULL)
        {
            ptr = strtok(NULL, " ");
            count++;
        }

        if (count > largestCount)
        {
            largestCount = count;
            strcpy(largestString, str[i]);
        }
    }

    printf("\nHighest number of distinct words is \"%s\", which has %d distinct words.\n", largestString, largestCount);
}