#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool isEven(int num)
{
    if (num % 2 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    int num;
    printf("Enter starting num:\n");
    scanf("%d", &num);

    while (num != 1)
    {
        if (isEven(num))
        {
            num /= 2;
        }
        else
        {
            num = (num * 3) + 1;
        }
        printf("%d\n", num);
    }
    return 0;
}