/*
Write a program that takes in a decimal number as input and converts it to binary. The program should output the binary number with leading zeros to make it 8 bits long.
Example:
Input: 10
Output: 00001010
Explanation: The decimal number 10 is equivalent to the binary number 00001010.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int DecitoBin(int num)
{
    int rem = 0, sum = 0, prod = 0, power = 1;
    while (num > 0)
    {
        rem = num % 2;
        prod = rem * power;
        power *= 10;
        sum += prod;
        num /= 2;
    }
    return sum;
}

int main()
{
    char str[100];
    printf("Enter inputs: ");
    gets(str);
    
    char *word = strtok(str, " ");
    while (word != NULL)
    {
        int num = atoi(word);
        printf("%08d ", DecitoBin(num));
        word = strtok(NULL, " ");
    }

    return 0;
}