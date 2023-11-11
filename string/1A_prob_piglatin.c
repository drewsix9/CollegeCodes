// Words starting with vowel letter e add og "ay"
// Words starting with constant letter, e pa last tung first letter then add "ay"

// ear = ayear
// dan = ayand

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isStartVow(char str[])
{
    if (str[0] == 'a' || str[0] == 'e' || str[0] == 'i' || str[0] == 'o' || str[0] == 'u' || str[0] == 'A' || str[0] == 'E' || str[0] == 'I' || str[0] == 'O' || str[0] == 'U')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void add_ay(char str[])
{
    int size = strlen(str) - 1;
    str[size + 1] = 'a';
    str[size + 2] = 'y';
    str[size + 3] = '\0';
    puts(str);
}

void exec_conso(char str[])
{
    int size = strlen(str) - 1;
    char temp = str[0];
    for (int i = 1; i <= size; i++)
    {
        str[i - 1] = str[i];
    }
    str[size] = temp;
    str[size + 1] = 'a';
    str[size + 2] = 'y';
    str[size + 3] = '\0';
    puts(str);
}

int main()
{
    char str[100];
    printf("Enter string: ");
    gets(str);

    if (isStartVow(str) == 1)
    {
        add_ay(str);
    }
    else
    {
        exec_conso(str);
    }
    return 0;
}
