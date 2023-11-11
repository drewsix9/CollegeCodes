#include <stdio.h>
#include <string.h>

int main()
{
    char str1[] = "dan";
    char str2[] = "DAN";

    if (strcasecmp(str1, str2) == 0)
    {
        printf("\nEqual!");
    }
    else if (strcasecmp(str1, str2) > 0)
    {
        printf("\nstr1 is greater");
    }
    else if (strcasecmp(str1, str2) < 0)
    {
        printf("\nstr2 is greater");
    }

    return 0;
}