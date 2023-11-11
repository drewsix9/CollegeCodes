#include <stdlib.h>
#include <stdio.h>

void resetarray(int arr[])
{
    for (int i = 0; arr[i] != NULL; i++)
    {
        arr[i] = NULL;
    }
}

void toArr1(int num1, int arr1[], int length)
{
    int temp = num1, place = length - 1, rem;
    while (temp > 0)
    {
        rem = temp % 10;
        arr1[place] = rem;
        place--;
        temp /= 10;
    }
}

void toArr2(int num2, int arr2[], int length)
{
    int temp = num2, place = length - 1, rem;
    while (temp > 0)
    {
        rem = temp % 10;
        arr2[place] = rem;
        place--;
        temp /= 10;
    }
}

void printarray(int newarr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", newarr[i]);
    }
}

void printAND(int num1, int num2, int arr1[], int arr2[], int length, int newarr[])
{
    toArr1(num1, arr1, length);
    toArr2(num2, arr2, length);

    for (int i = 0; i < length; i++)
    {
        if ((arr1[i] == 1) && (arr2[i] == 1))
        {
            newarr[i] = 1;
        }
        else
        {
            newarr[i] = 0;
        }
    }
    printf("\nOutput: ");
    printarray(newarr, length);
}

void printOR(int num1, int num2, int arr1[], int arr2[], int length, int newarr[])
{
    toArr1(num1, arr1, length);
    toArr2(num2, arr2, length);

    for (int i = 0; i < length; i++)
    {
        if ((arr1[i] == 1) || (arr2[i] == 1))
        {
            newarr[i] = 1;
        }
        else
        {
            newarr[i] = 0;
        }
    }
    printf("\nOutput: ");
    printarray(newarr, length);
}

void printXOR(int num1, int num2, int arr1[], int arr2[], int length, int newarr[])
{
    toArr1(num1, arr1, length);
    toArr2(num2, arr2, length);

    for (int i = 0; i < length; i++)
    {
        if (arr1[i] != arr2[i])
        {
            newarr[i] = 1;
        }
        else
        {
            newarr[i] = 0;
        }
    }
    printf("\nOutput: ");
    printarray(newarr, length);
}

int main()
{
    int n, num1[100], num2[100], choice, arr1[100], arr2[100], length, newarr[100], num;

    system("cls");
    // printf("Enter number of inputs: ");
    // scanf("%d", &n);
    printf("Enter length: ");
    scanf("%d", &length);
    printf("\nEnter inputs: ");
    // for (int i = 0; i < n; i++)
    // {
    //     scanf("%d", &num1[i]);
    // }

    // for (int i = 0; i < n; i++)
    // {
    //     scanf("%d", &num2[i]);
    // }

    do
    {
        scanf("%d", &num);
        if (num != 2)
        {
            num1[n] = num;
            n++;
        }

    } while (num != 2);

    n = 0;
    do
    {
        scanf("%d", &num);
        if (num != 2)
        {
            num2[n] = num;
            n++;
        }

    } while (num != 2);

    do
    {
        printf("\n[1] - Output Bitwise AND\n[2] - Output Bitwise OR\n[3] - Output Bitwise XOR\n[4] - EXIT\n\nEnter choice: ");
        scanf("%d", &choice);
        for (int i = 0; i < n; i++)
        {

            if (choice == 1)
            {
                printAND(num1[i], num2[i], arr1, arr2, length, newarr);
            }
            else if (choice == 2)
            {
                printOR(num1[i], num2[i], arr1, arr2, length, newarr);
            }
            else if (choice == 3)
            {
                printXOR(num1[i], num2[i], arr1, arr2, length, newarr);
            }
            else if (choice == 4)
            {
                break;
            }
            printf("\n");
            resetarray(arr1);
            resetarray(arr2);
        }
    } while (choice != 4);
    return 0;
}