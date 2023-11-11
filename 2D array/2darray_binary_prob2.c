
#include <stdio.h>
#include <math.h>

void toDecimal(int arr[100][100], int colsize[], int rows, int DeciArr[100][100])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < colsize[i]; j++)
        {
            int num = arr[i][j];

            int quot = 0, rem = 0, sum = 0, power = 0, prod = 0;
            for (;;)
            {
                quot = num / 10;
                rem = num % 10;

                prod = rem * pow(2, power);
                power++;
                sum = sum + prod;

                num = quot;
                if (num == 0)
                {
                    break;
                }
            }
            DeciArr[i][j] = sum;
        }
    }

    // print decimal
    // for (int i = 0; i < rows; i++)
    // {
    //     for (int j = 0; j < colsize[i]; j++)
    //     {
    //         printf("%d ", DeciArr[i][j]);
    //     }
    // }
}

void toOctal(int arr[100][100], int colsize[], int rows, int OctalArr[100][100], int DeciArr[100][100])
{
    int temparr[100];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < colsize[i]; j++)
        {
            int n = 0;
            int num = DeciArr[i][j];

            int quot = 0, rem = 0, sum = 0, power = 0, prod = 0;
            for (;;)
            {
                quot = num / 8;
                rem = num % 8;

                temparr[n++] = rem;

                num = quot;
                if (num == 0)
                {
                    break;
                }
            }

            sum = 0;
            int count = n - 1;
            prod = 0, sum = 0;
            for (int i = (n - 1); i >= 0; i--)
            {
                prod = temparr[i] * pow(10, count);
                count--;
                sum = sum + prod;
            }
            OctalArr[i][j] = sum;
        }
    }

    // print Octal
    // for (int i = 0; i < rows; i++)
    // {
    //     for (int j = 0; j < colsize[i]; j++)
    //     {
    //         printf("%d ", OctalArr[i][j]);
    //     }
    // }
}

int main()
{
    int rows, num;
    int arr[100][100];
    int DeciArr[100][100];
    int OctalArr[100][100];
    int colsize[100];
    printf("Enter number of rows: ");
    scanf("%d", &rows);

    for (int i = 0; i < rows; i++)
    {
        int j = 0;
        printf("Enter row %d: ", i + 1);
        do
        {
            scanf("%d", &num);
            if (num != 0)
            {
                arr[i][j] = num;
                j++;
            }
            colsize[i] = j;
        } while (num != 0);
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

    toDecimal(arr, colsize, rows, DeciArr);
    printf("\n");
    toOctal(arr, colsize, rows, OctalArr, DeciArr);
    printOutput(arr, rows, colsize, DeciArr, OctalArr);

    return 0;
}

void printOutput(int arr[100][100], int rows, int colsize[], int DeciArr[100][100], int OctalArr[100][100])
{

    for (int i = 0; i < rows; i++)
    {
        printf("Row %d:\n", i + 1);
        for (int j = 0; j < colsize[i]; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
        for (int j = 0; j < colsize[i]; j++)
        {
            printf("%d ", DeciArr[i][j]);
        }
        printf("\n");
        for (int j = 0; j < colsize[i]; j++)
        {
            printf("%d ", OctalArr[i][j]);
        }
        printf("\n");
        printf("\n");
    }
}