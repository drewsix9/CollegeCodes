#include <stdio.h>

int main()
{
    int choice;
    float temp, result;
    printf("[1] - Celsius to Fahrenheit\n");
    printf("[2] - Fahrenheit to Celsius \n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("Enter temperature: ");
        scanf("%f", &temp);
        result = (temp * 9 / 5) + 32;
        if (result > 100.4)
        {
            printf("\nYou have a Fever");
        }
        else
        {
            printf("\nYour temperature is Normal");
        }
    }
    else if (choice == 2)
    {
        printf("Enter temperature: ");
        scanf("%f", &temp);
        result = (temp - 32) * 5 / 9;
        if (result > 38)
        {
            printf("\nYou have a Fever");
        }
        else
        {
            printf("\nYour temperature is Normal");
        }
    }
    else
    {
        printf("\nWrong Input, program will be terminated...");
    }

    return 0;
}