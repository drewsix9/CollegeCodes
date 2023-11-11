#include <stdio.h>
#include <math.h>

void conversion(int num, int base, int convert)
{
    int sum = 0, prod = 0, rem = 0, power = 0;
    while (num > 0)
    {
        rem = num % convert;
        prod = rem * pow(base, power++);
        sum += prod;
        num /= convert;
    }
    if (convert == 8)
    {
        printf("\nOctal = %d", sum);
    }
    if (convert == 10)
    {
        printf("\nDecimal = %d", sum);
    }
}

main()
{
    int base, num, convert;
    printf("Enter number: ");
    scanf("%d", &num);
    printf("Enter base (10 or 8): ");
    scanf("%d", &base);
    printf("Enter convert to (10 or 8): ");
    scanf("%d", &convert);

    conversion(num, base, convert);

    return 0;
}