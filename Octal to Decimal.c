#include <stdio.h>
#include <math.h>

int myOctaltoDeci(int num)
{
    int temp = num;
    int digits;
    while (temp > 0)
    {
        digits++;
        temp /= 10;
    }

    int power = 0, rem = 0, prod = 0, sum = 0;
    while (num > 0)
    {
        rem = num % 10;
        prod = rem * pow(8, power++);
        sum = sum + prod;
        num /= 10;
    }
    return sum;
}

int main()
{
    int num;
    printf("Enter an Octal Digit: ");
    scanf("%d", &num);
    printf("Decimal = %d", myOctaltoDeci(num));
}