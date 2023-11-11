#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char password[100];
    printf("Enter a password: ");
    fgets(password, 100, stdin);

    int has_uppercase = 0;
    int has_digit = 0;
    int has_special = 0;

    for (int i = 0; i < (int)strlen(password); i++)
    {
        if (isupper(password[i]))
        {
            has_uppercase = 1;
        }
        else if (isdigit(password[i]))
        {
            has_digit = 1;
        }
        else if (strpbrk(&password[i], "!@#$%^&*()_-+={}[]|\\:;\"'<>,.?/"))
        {
            has_special = 1;
        }
    }

    if (has_uppercase && has_digit && has_special)
    {
        printf("Password is valid\n");
    }
    else
    {
        printf("Password is invalid\n");
    }

    return 0;
}
