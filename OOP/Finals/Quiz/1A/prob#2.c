#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void conversion(char *str2)
{
    int size = strlen(str2);
    int sum = 0;
    int power = 1;

    if (strchr(str2, '.'))
    {
        printf("%s ", str2);
    }
    else
    {
        for (int i = size - 1; i >= 0; i--)
        {
            if (str2[i] == '1')
            {
                sum += 1 * power;
            }
            power *= 2;
        }
        printf("%d ", sum);
    }
}

void binarytoDeci(char *str)
{
    int sum = 0;
    int prod;
    if (strchr(str, '.'))
    {
        printf("%s ", str);
    }
    else
    {
        int temp = atoi(str);
        int n = 0;
        while (temp > 0)
        {
            int rem = temp % 10;
            prod = rem * pow(2, n++);
            sum += prod;
            temp /= 10;
        }
        printf("%d ", sum);
    }
}

int main()
{
    char str[100];
    printf("Enter string of binary digits: ");
    fgets(str, 100, stdin);
    str[strlen(str) - 1] = '\0';

    char *ptr = strtok(str, " ");
    while (ptr != NULL)
    {
        binarytoDeci(ptr);
        ptr = strtok(NULL, " ");
    }

    return 0;
}