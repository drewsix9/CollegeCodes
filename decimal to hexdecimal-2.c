#include <stdio.h>
#include <string.h>

int main()
{
    int num = 7562;
    char str[100] = "";

    int n = 0, rem;

    while (num > 0)
    {
        rem = num % 16;
        if (rem < 10)
        {
            str[n] = '0' + rem;
        }
        else
        {
            str[n] = 'A' + (rem - 10);
        }
        n++;
        num /= 16;
    }

    strrev(str);
    printf("Hexadecimal: %s", str);

    return 0;
}