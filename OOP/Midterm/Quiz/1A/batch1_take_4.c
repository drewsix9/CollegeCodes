#include <stdio.h>

void setfreq(int freq[100][100])
{
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            freq[i][j] = -1;
        }
    }
}

void resetTemparr(int temparr[100][100])
{
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            temparr[i][j] = 0;
        }
    }
}

int printOccurIndex(int arr[100][100], int colsize[], int temparr[100][100], int rows, int tempcolsize[])
{
    resetTemparr(temparr);
    int n, totaln = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < colsize[i]; j++)
        {
            int count = 1;
            n = 0;
            for (int k = 0; k < rows; k++)
            {
                for (int l = 0; l < colsize[k]; l++)
                {
                    if (j == l && i == k)
                    {
                        continue; // skip elements in the same column and row
                    }
                    if (arr[i][j] == arr[k][l])
                    {
                        // printf("arr[%d][%d] = %d == arr[%d][%d] = %d\n", i, j, arr[i][j], k, l, arr[k][l]);
                        count++;
                        temparr[k][n] = i;
                        n++;
                        totaln++;
                    }
                }
            }
        }
        tempcolsize[i] = n;
    }
    return totaln;
}

int main()
{
    int rows;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    int arr[rows][100];
    int freq[100][100];
    int temparr[100][100];
    setfreq(freq);
    int colsize[rows];
    int tempcolsize[100];
    int temp;
    for (int i = 0; i < rows; i++)
    {
        int j = 0;
        printf("Enter row %d: ", i + 1);
        do
        {
            scanf("%d", &temp);
            if (temp != 0)
            {
                arr[i][j] = temp;
                j++;
            }
            colsize[i] = j;
        } while (temp != 0);
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < colsize[i]; j++)
        {
            int count = 1;
            for (int k = 0; k < rows; k++)
            {
                for (int l = 0; l < colsize[k]; l++)
                {
                    if (j == l && i == k)
                    {
                        continue; // skip elements in the same column and row
                    }
                    if (arr[i][j] == arr[k][l] && freq[i][j] != 0)
                    {
                        // printf("arr[%d][%d] = %d == arr[%d][%d] = %d\n", i, j, arr[i][j], k, l, arr[k][l]);
                        count++;
                        freq[k][l] = 0;
                        arr[k][l] = 0;
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
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("Freq: \n");
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
                printf("%d occured %d times @ Sets: ", arr[i][j], freq[i][j]);

                int n = printOccurIndex(arr, colsize, temparr, rows, tempcolsize);
                for (int k = 0; k < n; k++)
                {
                    for (int l = 0; l < tempcolsize[k]; l++)
                    {
                        printf("%d ", temparr[k][l]);
                    }
                }
                printf("\n");
            }
        }
    }

    return 0;
}
