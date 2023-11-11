#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
    Hexa to Decimal
    F1.1 == 241.0625
*/
int toHexa(char c)
{
    char hexa[] = "0123456789ABCDEF";
    char *ptr = strchr(hexa, c);
    return ptr - hexa;
}

int main()
{
    char str[100];
    printf("Enter hexadecimal: ");
    gets(str);
    printf("\nOutput: ");

    // strchr(str, '.') is mu return ug pointer sa kung asa ang decimal point, if dile siya maka kita then NULL pointer iyang i return
    char *ptr = strchr(str, '.');

    if (ptr != NULL)
    {
        // has decimal point
        int pos = ptr - str; // PTR (pointer sa kung asa ang decimal point) minus ang STR natu is equal to the index kung asa ang decimal point

        int power = 1, sum = 0, num = 0, prod;

        for (int i = pos - 1; i >= 0; i--)
        {
            num = toHexa(str[i]);
            prod = num * power;
            power *= 16;
            sum += prod;
        }
        printf("%d", sum);
        printf(".");

        float f_power = pow(16, -1), f_sum = 0, f_num = 0, f_prod;
        for (int i = pos + 1; i < strlen(str); i++)
        {
            f_num = toHexa(str[i]);
            f_prod = f_num * f_power;
            f_power /= 16;
            f_sum += f_prod;
        }

        char temp[100];
        // gi integer to string nato ang f_sum (0.0625) kay para ma output ra nato ang 0625
        sprintf(temp, "%f", f_sum);
        // temp+0 is pointer sa 0m temp+1 is pointer sa '.' maong sa temp+2 ta nag sugod ug print
        puts(temp + 2); // output ang tenths digit to the right....
    }
    else
    {
        // has NO decimal point
        int size = strlen(str);
        int power = 1, sum = 0, num = 0, prod;
        for (int i = size - 1; i >= 0; i--)
        {
            num = toHexa(str[i]);
            prod = num * power;
            power *= 16;
            sum += prod;
        }
        printf("%d", sum);
    }

    return 0;
}