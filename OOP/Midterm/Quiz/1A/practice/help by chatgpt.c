#include <stdio.h>

#define ROWS 3
#define COLS 3

void find_frequency(int arr[ROWS][COLS])
{
    int i, j, k, freq;
    int visited[ROWS][COLS] = {0};
    int unique_elements[ROWS * COLS], count = 0;

    /* Find the frequency of each element in the array */
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            freq = 1;

            /* Check if this element is already counted */
            if (visited[i][j])
            {
                continue;
            }

            /* Count the frequency of this element */
            for (k = i + 1; k < ROWS; k++)
            {
                if (arr[i][j] == arr[k][j])
                {
                    freq++;
                    visited[k][j] = 1;
                }
            }
            for (k = j + 1; k < COLS; k++)
            {
                if (arr[i][j] == arr[i][k])
                {
                    freq++;
                    visited[i][k] = 1;
                }
            }

            /* Store this element and its frequency in unique_elements array */
            unique_elements[count++] = arr[i][j];
            unique_elements[count++] = freq;

            /* Mark this element as visited */
            visited[i][j] = 1;
        }
    }

    /* Print each element and its frequency only once */
    printf("Element\tFrequency\n");
    for (i = 0; i < count; i += 2)
    {
        printf("%d\t%d\n", unique_elements[i], unique_elements[i + 1]);
    }
}

int main()
{
    int arr[ROWS][COLS] = {{1, 2, 1},
                           {2, 3, 3},
                           {4, 2, 1}};

    find_frequency(arr);

    return 0;
}
