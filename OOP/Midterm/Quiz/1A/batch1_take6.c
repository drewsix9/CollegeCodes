#include <stdio.h>

void printingFinal(int newarr[], int size, int freq[], int pos[])
{
    for (int i = 0; i < size; i++)
    {
        if (freq[i] > 1)
        {
            printf("element %d occured %d times in Sets:  ", newarr[i], freq[i]);
            for (int j = 0; j < size; j++)
            {
                if (newarr[i] == newarr[j])
                {
                    printf("%d ", pos[j]);
                }
            }
            printf("\n");
        }
    }
}

void takingFrequency(int newarr[], int size, int freq[])
{
    for (int i = 0; i < size; i++)
    {
        int count = 1;
        for (int j = i + 1; j < size; j++)
        {
            if (newarr[i] == newarr[j])
            {
                count++;
                freq[j] = 0;
            }
        }
        if (freq[i] != 0)
        {
            freq[i] = count;
        }
    }
}
int main()
{
    int rows;
    printf("Enter number of arrays: ");
    scanf("%d", &rows);
    int colsize[rows], arr[rows][100];

    int temp;
    for (int i = 0; i < rows; i++)
    {
        int j = 0;
        while (scanf("%d", &temp) == 1 && temp != 0)
        {
            arr[i][j++] = temp;
        }
        colsize[i] = j;
    }

    int newarr[100];
    int pos[100];
    int size = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < colsize[i]; j++)
        {
            newarr[size] = arr[i][j];
            pos[size] = i + 1;
            size++;
        }
    }

    int freq[size];
    for (int i = 0; i < size; i++)
    {
        freq[i] = -1;
    }

    takingFrequency(newarr, size, freq);

    printf("\nOutput:\n");
    printingFinal(newarr, size, freq, pos);

    return 0;
}
