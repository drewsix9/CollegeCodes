#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void toDeci(char *str)
{
    int size = strlen(str);
    int sum = 0, place = 1;
    for (int i = size - 1; i >= 0; i--)
    {
        if (str[i] == '1')
        {
            sum += 1 * place;
        }
        place *= 2;
    }
    printf("%d ", sum);
}

int main()
{
    char buffer[100];
    printf("Enter inputs: ");
    fgets(buffer, 100, stdin);

    char nonwords[] = " \n\t";
    char str[100][100];

    int n = 0;
    char *ptr = strtok(buffer, nonwords);
    while (ptr != NULL)
    {
        strcpy(str[n], ptr);
        ptr = strtok(NULL, nonwords);
        n++;
    }

    printf("\nOutput: ");
    for (int i = 0; i < n; i++)
    {
        toDeci(str[i]);
    }

    return 0;
}