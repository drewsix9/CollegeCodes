#include <stdio.h>

int main()
{
    int rows;
    printf("Enter number of rows: ");
    scanf("%d", &rows);

    int arr[rows][100];
    int colsize[rows];

    // read input sets
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

    // count occurrences
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < colsize[i]; j++)
        {
            int count = 0;
            for (int k = 0; k < rows; k++)
            {
                for (int l = 0; l < colsize[k]; l++)
                {
                    if (arr[i][j] == arr[k][l])
                    {
                        count++;
                        break; // count once per set
                    }
                }
            }
            if (count >= 2)
            {
                printf("%d occurred %d times in Set: ", arr[i][j], count);
                for (int k = 0; k < rows; k++)
                {
                    for (int l = 0; l < colsize[k]; l++)
                    {
                        if (arr[i][j] == arr[k][l])
                        {
                            printf("%d ", k + 1);
                            break; // list once per set
                        }
                    }
                }
                printf("\n");
            }
        }
    }

    return 0;
}
