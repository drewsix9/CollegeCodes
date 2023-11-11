#include <stdio.h>
#include <string.h>

int main()
{
    int rows;
    printf("Enter how many strings: ");
    scanf("%d", &rows);
    fflush(stdin);;
    char names[rows][50];

    for (int i = 0; i < rows; i++)
    {
        gets(names[i]);
    }

    printf("\nInputs:\n");
    for (int i = 0; i < rows; i++)
    {
        puts(names[i]);
    }

    char temp[100];
    for (int i = 0; i < rows; i++)
    {
        for (int j = i + 1; j < rows; j++)
        {
            if (names[i][0] > names[j][0])
            {
                strcpy(temp, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], temp);
            }
        }
    }

    printf("\nsorted:\n");
    for (int i = 0; i < rows; i++)
    {
        puts(names[i]);
    }
}