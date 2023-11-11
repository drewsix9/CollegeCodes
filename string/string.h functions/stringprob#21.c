/*
    Problem 4: Arrange the binary only in Descending
    Input: 1010 2004 1100 1111
    Output: 1111 1100 1010
*/

#include <stdio.h>
#include <string.h>

int isBinary(char *num)
{
    int x = strspn(num, "01");
    if (x == strlen(num))
    {
        return 1;
    }
    return 0;
}

int main()
{
    int arr[100], size;

    printf("Enter # of inputs: ");
    scanf("%d", &size);
    printf("Enter inputs: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    int binary[100];
    int n = 0;
    for (int i = 0; i < size; i++)
    {
        char temp[100];
        sprintf(temp, "%d", arr[i]);
        if (isBinary(temp))
        {
            binary[n++] = arr[i];
        }
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (binary[i] < binary[j])
            {
                int temp = binary[i];
                binary[i] = binary[j];
                binary[j] = temp;
            }
        }
    }

    printf("\nOutput: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", binary[i]);
    }
}