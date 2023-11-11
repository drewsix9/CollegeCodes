#include <stdio.h>

int main()
{
    int num, sum = 0, prod = 0;
    printf("Enter a number: ");
    scanf("%d", &num);
    for (int i = 0; i <= num; i++)
    {
        prod = i * i;
        sum += prod;
        printf("%d\n", prod);
    }
    printf("Sum = %d\n", sum);
    return 0;
}