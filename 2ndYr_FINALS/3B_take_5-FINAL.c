#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findDeciPoint(char str[])
{
    int size = strlen(str) - 1;

    int i = 0;
    while (i < size && str[i] != '.')
    {
        i++;
    }
    return i;
}

void resetstring(char str[])
{
    for (int i = 0; str[i] != NULL; i++)
    {
        str[i] = NULL;
    }
}

void ReversePrinting(char str[], int pos)
{
    int size = strlen(str) - 1;
    for (int i = 0; i <= pos - 1; i++)
    {
        printf("%c", str[i]);
    }
    printf(".");
    for (int i = size; i > pos; i--)
    {
        if (str[i] != '0')
        {
            printf("%c", str[i]);
        }
    }
}

int main()
{
    float arr[100], temp;
    int n = 0;
    printf("Enter numbers: ");
    do
    {
        scanf("%f", &temp);
        if (temp != 0)
        {
            arr[n++] = temp;
        }
    } while (temp != 0);

    printf("\nOutput: ");
    char str[100];
    for (int i = 0; i < n; i++)
    {
        float cast = (int)arr[i];
        if (arr[i] - cast != 0)
        {
            resetstring(str);
            sprintf(str, "%f", arr[i]); // converts float to string
            ReversePrinting(str, findDeciPoint(str));
            printf(" ");
        }
        else
        {
            printf("%.0f", arr[i]);
            printf(" ");
        }
    }
    return 0;
}
