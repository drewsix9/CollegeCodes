#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool isPrime(int num)
{
    if (num <= 1)
    {
        return false;
    }
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
    int size = strlen(str);
    int pos_space = 0;
    for (int i = 0; i < size; i++)
    {
        int pos_first = i;
        int count = 0;
        for (int j = i; j < size; j++)
        {
            if (!isspace(str[j]))
            {
                count++;
                i++;
            }
            else
            {
                pos_space = j;
                break;
            }
        }
        // printf("read the word  it had %d letters\n", count);
        if (isPrime(count))
        {
            if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
            {
                // vowel
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
                char temp = str[pos_first];
                for (int k = pos_first + 1; k <= count - 2; k++)
                {
                    str[k - 1] = str[k];
                }
                str[count - 1] = temp;
                //*move twice*
                int count3 = 0;
                while (count3 != 2)
                {
                    for (int p = strlen(str) + count3; p >= pos_space + count3; p--)
                    {
                        str[p] = str[p - 1];
                    }
                    count3++;
                }
                str[pos_space] = 'a';
                str[pos_space + 1] = 'y';
            }
        }
    }
    str[strlen(str)] = '\0';
    puts(str);
    return 0;
}
