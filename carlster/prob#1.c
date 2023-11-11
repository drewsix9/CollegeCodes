// Ask the user to input an integer n.
// Print its value with a new line and increment the integer by 1 while it is not divisible by 3, 5, and 7.
#include <stdlib.h>
#include <stdio.h>

void printdiv_3_5_7(int limit)
{
    for (int i = 2; i < limit; i++)
    {
        if (i % 3 == 0 && i % 5 == 0 && i % 7 == 0)
        {
            printf("%d\n", i);
        }
    }
}

int main()
{
    system("cls");
    int num;
    printf("Enter input: ");
    scanf("%d", &num);

    while ((num % 3 != 0) || (num % 5 != 0) || (num % 7 != 0))
    {
        num++;
        printf("%d\n", num);
    }

    printf("numbers divisible by 3,5,7 are:\n");
    printdiv_3_5_7(2000);

    return 0;
}
