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

int main()
{
    int rows, cols;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);
    int arr[rows][cols];
    int freq[rows][cols];
    for (int i = 0; i < rows; i++)
    {
        printf("Enter row %d: ", i + 1);
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("\n");
    for (int i = 0; i < rows; i++)
    {
        printf("row %d: ", i + 1);
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            int count = 1;
            for (int k = 0; k < rows; k++)
            {
                for (int l = 0; l < cols; l++)
                {
                    if (j == l && i == k)
                    {
                        continue;
                    }
                    if (arr[i][j] == arr[k][l] && freq[i][j] != 0)
                    {
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
        printf("row %d: ", i + 1);
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    for (int i = 0; i < rows; i++)
    {
        printf("Freq row %d: ", i + 1);
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", freq[i][j]);
        }
        printf("\n");
    }

    return 0;
}