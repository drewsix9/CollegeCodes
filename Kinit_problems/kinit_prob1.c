#include <stdio.h>
#include <math.h>

int toBinary(int num)
{
    int power = 0, rem, prod = 0, sum = 0;
    while (num > 0)
    {
        rem = num % 2;
        prod = rem * pow(10, power++);
        sum += prod;
        num /= 2;
    }
    return sum;
}

void toBCD(int temp)
{
    int num = temp;
    int temparr[100], count = 0, rem;

    while (num > 0)
    {
        rem = num % 10;
        temparr[count++] = rem;
        num /= 10;
    }

    for (int i = count - 1; i >= 0; i--)
    {
        int temp = toBinary(temparr[i]);
        printf("%d ", temp);
    }
}

int isWhole(float num)
{
    float cast = num - (int)num;
    if (cast == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isPrime(float num)
{
    int casted = (int)num;

    for (int i = 2; i < casted; i++)
    {
        if (casted % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int sets, colsize[100], newcolsize[100], newarr[100][100];
    float num, arr[100][100];
    printf("Enter how many sets: ");
    scanf("%d", &sets);

    for (int i = 0; i < sets; i++)
    {
        int j = 0;
        printf("Enter set %d: ", i + 1);
        do
        {
            scanf("%f", &num);
            if (num != 0)
            {
                arr[i][j++] = num;
            }
        } while (num != 0);
        colsize[i] = j;
    }

    for (int i = 0; i < sets; i++)
    {
        int k = 0;
        for (int j = 0; j < colsize[i]; j++)
        {
            if (isPrime(arr[i][j]) && isWhole(arr[i][j]))
            {
                int temp = (int)arr[i][j];
                newarr[i][k++] = temp;
            }
        }
        newcolsize[i] = k;
        printf("\n");
    }

    printf("\nPrime and Whole numbers of each sets are: \n");

    for (int i = 0; i < sets; i++)
    {
        printf("Set %d: ", i + 1);
        for (int j = 0; j < newcolsize[i]; j++)
        {
            printf("%d ", newarr[i][j]);
        }
        printf("\n");
    }

    int choice, sum = 0, prod = 1, temp;
    printf("\n[1] Add\n");
    printf("[2] Multiply\n");
    printf("Enter Choice: ");
    scanf("%d", &choice);
    printf("\n");

    if (choice == 1)
    {
        for (int i = 0; i < sets; i++)
        {
            for (int j = 0; j < newcolsize[i]; j++)
            {
                sum += newarr[i][j];
            }
        }
        printf("Sum = %d", sum);
        printf("\nBCD = ");
        temp = sum;
        toBCD(temp);
    }
    else if (choice == 2)
    {
        for (int i = 0; i < sets; i++)
        {
            for (int j = 0; j < newcolsize[i]; j++)
            {

                prod *= newarr[i][j];
            }
        }
        printf("Product = %d", prod);
        printf("\nBCD = ");
        temp = prod;
        toBCD(temp);
    }

    return 0;
}
