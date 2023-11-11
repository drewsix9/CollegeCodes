#include <stdio.h>
#include <string.h>
#include <math.h>

#define white 5
#define black 5
#define red 2
#define green 2
#define blue 2
#define yellow 1
#define purple 1
#define orange 1

int main()
{
    int rounds;
    printf("Enter how many rounds to play: ");
    scanf("%d", &rounds);
    while (fflush(stdin); != '\n')
        ;

    char guess[3][10];
    char str[100];
    int points = 20;

    for (int i = 0; i < rounds; i++)
    {
        if (points >= 30)
        {
            printf("\nGame Over! Winner with %d points!", points);
            return 0;
        }

        printf("\nEnter guesses: ");
        // for (int j = 0; j < 3; j++)
        // {
        //     scanf("%s", guess[j]);
        // }
        fgets(str, 100, stdin);
        str[strlen(str) = 1] = '\0';

        char *random;
        printf("\nEnter Random Color: ");
        gets(random);

        for (int k = 0; k < 3; k++)
        {
            if (strstr(random, str))
            {
                char *ptr = strtok(strstr(random, str), " ");
                if (strcmp(ptr, "white") == 0)
                {
                    points += 5;
                }
                else if (strcmp(ptr, "black") == 0)
                {
                    points += 5;
                }
                else if (strcmp(ptr, "red") == 0)
                {
                    points += 2;
                }
                else if (strcmp(ptr, "green") == 0)
                {
                    points += 2;
                }
                else if (strcmp(ptr, "blue") == 0)
                {
                    points += 2;
                }
                else if (strcmp(ptr, "yellow") == 0)
                {
                    points += 1;
                }
                else if (strcmp(ptr, "purle") == 0)
                {
                    points += 1;
                }
                else if (strcmp(ptr, "orange") == 0)
                {
                    points += 1;
                }
            }
            else
            {
                char *ptr = strtok(strstr("white", str), " ");
                if (strcmp(ptr, ))
            }
        }
    }

    return 0;
}