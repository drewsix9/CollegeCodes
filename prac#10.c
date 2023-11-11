// Prompts the user to enter a string of characters (maximum 100 characters).
// Determine if the length of the string is a prime number. If the length of the string is not a prime number, display a message indicating this and terminate the program.
// If the length of the string is a prime number, compute the factorial of the length of the string.

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX 100

bool isPrime(char str[], int length);
int factorial(int length);
int main()
{
    char str[MAX];
    int arr[MAX];
    printf("Enter a string: ");
    scanf("%s", str);
    int length = strlen(str);

    if (isPrime(str, length))
    {
        printf("The length of the string '%s' is a prime number.\n", str);
        printf("The factorial of the length of the string is %d.\n", factorial(length));
    }
    else
    {
        printf("length of %s is a NOT prime number", str);
    }

    return 0;
}

bool isPrime(char str[], int length)
{
    for (int i = 2; i < length; i++)
    {
        if (length % i == 0)
        {
            return false;
        }
    }
    return true;
}

int factorial(int length)
{
    int factorial = 1;
    for (int i = 2; i <= length; i++)
    {
        factorial *= i;
    }
    return factorial;
}