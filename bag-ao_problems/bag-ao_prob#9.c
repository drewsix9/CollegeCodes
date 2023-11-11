#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int temp_to_string(char tempstr[], char str[], int j)
{
    int size = strlen(tempstr);

    for (int i = 0; i < size; i++)
    {
        str[j] = tempstr[i];
        j++;
    }
    return j;
}

void resetstring(char tempstr[])
{
    for (int i = 0; tempstr[i] != NULL; i++)
    {
        tempstr[i] = NULL;
    }
}

int main()
{
    int size;
    printf("Enter number of students: ");
    scanf("%d", &size);
    char str[100];
    char tempstr[100];
    int pos_1stletter[size];
    int score[size];
    int choice = 0;

    int j = 0;
    for (int i = 0; i < size; i++)
    {
        printf("\nEnter name of Student:\n");
        resetstring(tempstr); // string sudlan sa names
        scanf("%s", tempstr);
        j = temp_to_string(tempstr, str, j);
        str[j] = ' '; // adds a space every after name.
        j++;
        pos_1stletter[i] = j - strlen(tempstr) - 1; // takes note of the index of the 1st letter of the name
        printf("Enter %s's score:\n", tempstr);
        scanf("%d", &score[i]);
        printf("\n");
    }

    printf("[1] Print students who passed\n");
    printf("[2] Print students who failed\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("\nStudents who passed are the following: \n");
        for (int i = 0; i < size; i++)
        {
            if (score[i] >= 75)
            {
                int k = pos_1stletter[i];
                while (str[k] != ' ')
                {
                    printf("%c", str[k]);
                    k++;
                }
                printf("\n");
            }
        }
    }

    if (choice == 2)
    {
        printf("\nStudents who failed are the following: \n");
        for (int i = 0; i < size; i++)
        {
            if (score[i] < 75)
            {
                int k = pos_1stletter[i];
                while (str[k] != ' ')
                {
                    printf("%c", str[k]);
                    k++;
                }
                printf("\n");
            }
        }
    }

    return 0;
}
