#include <stdio.h>

#define row1 3
#define cols1 3

void populate(int arr[100][100], int row, int cols)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
}

void printArr(int arr[][100], int row, int colsize[])
{
    for (int i = 0; i < row; i++)
    {
        printf(" Row %d: ", i + 1);
        for (int j = 0; j < colsize[i]; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void setfreq(int freq[3][3], int row, int cols)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            freq[i][j] = -1;
        }
    }
}

int main()
{
    int row = row1, cols = cols1;
    int arr[row1][cols1];
    int freq[row][cols];
    int temp;
    int colsize[row];
    int j;
    printf("Enter inputs: \n");
    for (int i = 0; i < row; i++)
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

    printArr(arr, row, colsize);
    setfreq(freq, row, cols);

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < colsize[i]; j++)
        {
            for (int k = 0; k < row; k++)
            {
                for (int l = 0; l < colsize[k]; l++)
                {
                    if (l == j && i == k)
                    {
                        continue;
                    }
                    if (arr[i][j] == arr[k][l])
                    {
                        printf("%d and %d are equal\n", arr[i][j], arr[k][l]);
                    }
                }
            }
        }
    }

    // for (int i = 0; i < row; i++)
    // {
    //     for (int j = 0; j < cols; j++)
    //     {
    //         if (freq[i][j] >= 2)
    //         {
    //             printf("%d occured %d times\n", arr[i][j], freq[i][j]);
    //         }
    //     }
    // }

    return 0;
}