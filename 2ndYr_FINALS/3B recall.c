#include <stdio.h>
#include <math.h>
#include <string.h>

int isWhole(float num)
{
    float cast = num - (int)num;
    if (cast == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int findDeci(char *str)
{
    int i = 0;
    while (str[i] != '.')
    {
        i++;
    }
    return i;
}

void reversing(float num)
{
    printf("%d.", (int)num);

    char str[100];
    sprintf(str, "%f", num);
    int pos = findDeci(str);
    for (int i = strlen(str) - 1; i > pos; i--)
    {
        if (str[i] != '0')
        {
            printf("%c", str[i]);
        }
    }
}

int main()
{
    int n = 0;
    float arr[100], num;

    while (scanf("%f", &num) == 1 && num != 0)
    {
        arr[n++] = num;
    }

    for (int i = 0; i < n; i++)
    {
        if (isWhole(arr[i]) == 1)
        {
            printf("%d ", (int)arr[i]);
        }
        else
        {
            reversing(arr[i]);
            printf(" ");
        }
    }

    return 0;
}