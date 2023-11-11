#include <stdio.h>
#include <string.h>

int main()
{
    int num = 7562;
    char str[100] = "";

    int rem = 0;
    while (num > 0)
    {
        rem = num % 16;
        switch (rem)
        {
        case 10:
            strcat(str, "A");
            break;
        case 11:
            strcat(str, "B");
            break;
        case 12:
            strcat(str, "C");
            break;
        case 13:
            strcat(str, "D");
            break;
        case 14:
            strcat(str, "E");
            break;
        case 15:
            strcat(str, "F");
            break;
        default:
            char temp[5];
            sprintf(temp, "%d", rem);
            strcat(str, temp);
            break;
        }
        num /= 16;
    }

    strrev(str);
    printf("Hexadecimal: %s", str);
}