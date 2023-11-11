#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char **argv)
{
    int n, i, j, temp;
    printf("input the size of the array:");
    scanf("%d", &n);

    int arr[n];

    printf("input %d of elements in the array:\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("element - %d :", i);
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("element of array in sorted ascending order are:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}