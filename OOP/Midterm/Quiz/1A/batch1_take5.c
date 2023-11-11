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

void resetTemparr(int temparr[])
{
    for (int i = 0; temparr[i] != NULL; i++)
    {
        temparr[i] = 0;
    }
}

int printOccurIndex(int arr[100][100], int colsize[], int temparr[], int rows, int num)
{
    resetTemparr(temparr);
    int n = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < colsize[i]; j++)
        {
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
                        if (arr[i][j] == num)
                        {
                            if (temparr[n - 1] == i + 1) // check if i+1 is already placed in temparr[]
                            {
                                continue;
                            }
                            temparr[n] = i + 1;
                            n++;
                        }
                    }
                }
            }
        }
    }
    return n;
}

int main()
{
    int rows;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    int arr[rows][100];
    int freq[100][100];
    int temparr[100];
    setfreq(freq);
    int colsize[rows];
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
                arr[i][j++] = temp;
            }
        } while (temp != 0);
        colsize[i] = j;
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
    printf("\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < colsize[i]; j++)
        {
            if (freq[i][j] >= 2)
            {
                printf("%d occured %d times @ Sets: ", arr[i][j], freq[i][j]);
                int num = arr[i][j];
                int n = printOccurIndex(arr, colsize, temparr, rows, num);
                for (int k = 0; k < n; k++)
                {
                    printf("%d ", temparr[k]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}