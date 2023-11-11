#include <stdio.h>

int main()
{
    int sets;
    printf("Enter number of sets: ");
    scanf("%d", &sets);

    int row = sets;
    int arr[row][100];
    int setsize[row];

    printf("Enter elements:\n");
    int temp, j = 0, n = 0;
    for (int i = 0; i < sets; i++)
    {
        j = 0;
        printf("Enter Set[%d]: ", i + 1);
        do
        {
            scanf("%d", &temp);
            if (temp != 0)
            {
                arr[i][j] = temp;
                j++;
            }
        } while (temp != 0);
        setsize[n++] = j;
    }

    printf("\n");
    for (int i = 0; i < sets; i++)
    {
        for (int k = 0; k < setsize[i]; k++)
        {
            printf("%d ", arr[i][k]);
        }
        printf("\n");
    }

    int freq[row][100];
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            freq[i][j] = -1;
        }
    }

    int numberofrepeating = 0;
    int numtostore[100];
    for (int i = 0; i < sets; i++)
    {
        for (int j = 0; j < setsize[i]; j++)
        {
            int count = 1;
            for (int k = i + 1, l = j + 1; k < sets, l < setsize[i]; k++, l++)
            {
                if (arr[i][j] == arr[k][l])
                {
                    count++;
                    freq[k][l] = 0;
                }
            }
            if (freq[i][j] != 0)
            {
                numtostore[numberofrepeating] = arr[i][j];
                numberofrepeating++;
                freq[i][j] = count;
            }
        }
    }

    for (int m = 0; m < numberofrepeating; m++)
    {
        for (int i = 0; i < sets; i++)
        {
            for (int j = 0; j < setsize[i]; j++)
            {
                if (freq[i][j] >= 2)
                {
                    printf("%d occured %d times\n", numtostore[m], freq[i][j]);
                }
            }
        }
    }

    return 0;
}