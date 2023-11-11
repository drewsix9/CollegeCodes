#include <stdio.h>

void populateArray(int arr[][100], int row, int colsize[])
{
    int temp;
    for (int i = 0; i < row; i++)
    {
        int j = 0;
        printf("Enter set %d: ", i + 1);
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
}

void printArray(int arr[][100], int row, int colsize[])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < colsize[i]; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void setfreq(int freq[][100], int row)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            freq[i][j] = 0;
        }
    }
}

void checkoccurence(int arr[][100], int row, int colsize[], int freq[row][100])
{
    int l = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < colsize[i]; j++)
        {
            int count = 1;
            for (int k = i; k < row; k++)
            {
                if (k == i)
                {
                    l = j + 1;
                }
                else
                {
                    l = 0;
                }
                for (; l < colsize[i]; l++)
                {
                    if (arr[i][j] == arr[k][l])
                    {
                        printf("%d and %d are equal\n", arr[i][j], arr[k][l]);
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

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < colsize[i]; j++)
        {
            if (freq[i][j] >= 2)
            {
                printf("%d occured %d times", arr[i][j], freq[i][j]);
            }
        }
    }
}

int main()
{
    int row;
    printf("Enter number of sets: ");
    scanf("%d", &row);
    int colsize[row];
    int arr[row][100];
    int freq[row][100];
    setfreq(freq, row);
    printf("\n");

    populateArray(arr, row, colsize);
    printArray(arr, row, colsize);
    checkoccurence(arr, row, colsize, freq);

    return 0;
}