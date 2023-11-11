#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 100

void resetString(char str[])
{
    for (int i = 0; str[i] != NULL; i++)
    {
        str[i] = NULL;
    }
}

void resetFreq(int freq[])
{
    for (int i = 0; i < 100; i++)
    {
        freq[i] = -1;
    }
}

bool isUnique(char str[], int pos, int count)
{
    int tempcount;
    int freq[MAX];
    resetFreq(freq);

    for (int i = pos; i < count; i++)
    {
        tempcount = 0;
        for (int j = i + 1; j < count; j++)
        {
            if (str[i] == str[j])
            {
                tempcount++;
                freq[j] = 0;
            }
        }
        if (freq[i] != 0)
        {
            freq[i] = tempcount;
        }
    }

    for (int i = 0; i < count - pos; i++)
    {
        if (freq[i] > 0)
        {
            return false;
        }
    }
    return true;
}

void printword(char str[], int pos, int count)
{
    for (int i = pos; i < count; i++)
    {
        printf("%c", str[i]);
    }
}

bool islargest(int num, int lettercount[], int nn)
{
    int largest = lettercount[0];
    for (int i = 0; i < nn; i++)
    {
        if (lettercount[i] > largest)
        {
            largest = lettercount[i];
        }
    }
    if (num == largest)
    {
        return true;
    }
    return false;
}

int main()
{
    char str[MAX];
    printf("Enter a string of words: ");
    gets(str);
    int size = strlen(str) - 1;
    int pos_1stletter[MAX];
    int lettercount[MAX];
    int nn = 0;

    for (int i = 0; i <= size; i++)
    {
        pos_1stletter[nn] = i;
        int j = i;
        int count = 0;
        while (j <= size && str[j] != ' ')
        {
            count++;
            j++;
        }
        lettercount[nn] = count;
        nn++;
        i = j;
    }

    printf("\n");
    for (int i = 0; i < nn; i++)
    {
        if (isUnique(str, pos_1stletter[i], lettercount[i] + pos_1stletter[i]) && islargest(lettercount[i], lettercount, nn))
        {
            printf("Output: %d ", lettercount[i]);
            printword(str, pos_1stletter[i], lettercount[i] + pos_1stletter[i]);
        }
        printf("\n");
    }
    return 0;
}
