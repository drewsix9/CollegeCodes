#include <stdio.h>
#include <string.h>

int main()
{
    char str[100], key[100];
    printf("Enter string: ");
    gets(str);

    printf("\nEnter word to be removed: ");
    gets(key);

    char *ptr = strstr(str, key); // pangitaon niya ang 'key' if naa ba siya sa 'str', if naa, mu return ug char pointer ang strstr() sa kung asa niya na kit.an ang 'key';
    while (ptr != NULL)
    {

        int pos = ptr - str; // if i subtract ang pointer ug ang str, makuha nimo ang index sa kung asa nakita strstr();
        int sizekey = strlen(key);
        int i, j;

        // if makita nato ang 'key' sulod sa 'str' atong i shift to the left ang characters. ang amount sa pag shift is mag depende sa size sa imong 'key'

        /*

        str = "hello world"
        key = "or";

                    ptr
                     |
                     v
        h e l l o  w o r l d

        iteration 1: h e l l o  w o l d
        iteration 2: h e l l o  w l d

        kaduha ta nag shift kay (2) mn sd ang length sa atong key, which is ang main purpose sa outerloop nato dre sa ubos.

        */

        for (i = 0; i < sizekey; i++)
        {
            for (j = pos + sizekey - i; j < strlen(str); j++)
            {
                str[j - 1] = str[j];
            }
            // since nag shift ta sa mga elements to the left, minusan nato ang last element sa char array
            str[j - 1] = '\0';
        }
        ptr = strstr(str, key);
    }

    printf("\n\nOutput: %s", str);

    return 0;
}