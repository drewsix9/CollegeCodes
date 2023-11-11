#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool isPrime(int num)
{
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    char str[100];
    gets(str);
    int size = strlen(str) - 1;
    int pos_space = 0;

    for (int i = 0; i <= size; i++)
    {
        printf("\n");
        int count = 0;
        for (int j = i; j <= size; j++)
        {
            if (str[j] != ' ')
            {
                count++;
                i++;
                printf("count = %d\n", count);
                printf("i = %d\n", i);
            }
            else
            {
                pos_space = j;
                break;
            }
        }
        printf("j = %d\n", pos_space);
        if (isPrime(count))
        {
            if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
            {
                // vowel
                //*move twice*
                int count2 = 0;
                while (count2 != 2)
                {
                    for (int p = strlen(str); p >= pos_space; p--)
                    {
                        str[p] = str[p - 1];
                    }
                    count2++;
                }

                str[count] = 'a';
                str[count + 1] = 'y';
            }
            else
            {
                // consonant
                char temp = str[i];
                for (int k = i + 1; k < count; k++)
                {
                    str[k - 1] = str[k];
                }
                str[count - 1] = temp;
                //*move twice*
                int count3 = 0;
                while (count3 != 2)
                {
                    for (int p = strlen(str); p >= pos_space; p--)
                    {
                        str[p] = str[p - 1];
                    }
                    count3++;
                }
                str[count] = 'a';
                str[count + 1] = 'y';
            }
        }
    }
    str[strlen(str)] = '\0';
    puts(str);
    return 0;
}
