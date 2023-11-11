#include <stdio.h>

void setfreq(int freq[][100], int row)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            freq[i][j] = -1;
        }
    }
}

int main()
{
    int rows;
    printf("Enter number of sets: ");
    scanf("%d", &rows);

    int arr[rows][100], colsize[rows], j = 0, temp;
    int freq[rows][100];
    printf("Enter inputs: \n");
    for (int i = 0; i < rows; i++)
    {
        printf("Enter row %d: ", i + 1);
        j = 0;
        do
        {
            scanf("%d", &temp);
            if (temp != 0)
            {
                arr[i][j++] = temp;
            }
        } while (temp != 0);
        colsize[i] = j;
    }

    printf("\nInputs:\n");
    for (int i = 0; i < rows; i++)
    {
        printf("Row %d: ", i + 1);
        for (int j = 0; j < colsize[i]; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    setfreq(freq, rows);

    int temparr[rows][100], countoccur;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < colsize[i]; j++)
        {
            int count = 1;
            countoccur = 0;
            for (int k = 0; k < rows; k++)
            {
                for (int l = 0; l < colsize[i]; l++)
                {
                    if (k == i && l == j)
                    {
                        continue;
                    }
                    if (arr[i][j] == arr[k][l])
                    {
                        printf("%d = arr[%d][%d] and %d = arr[%d][%d] are equal\n", arr[i][j], i, j, arr[k][l], k, l);
                        count++;
                        freq[k][l] = 0;
                    }
                }
            }
            if (freq[i][j] != 0)
            {
                freq[i][j] = count;
            }
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < colsize[i]; j++)
        {
            printf("%d ", freq[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < colsize[i]; j++)
        {
            if (freq[i][j] >= 2)
            {
                printf("%d occured %d times Set: ", arr[i][j], freq[i][j]);
            }
        }
    }

    return 0;
}