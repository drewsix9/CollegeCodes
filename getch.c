#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main()
{
    while (1)
    {
        int choice = 0;
        printf("\n[1] - My world!\n");
        printf("[2] - Hello word!\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("\nOutput: My world!\n");
        }
        else if (choice == 2)
        {
            printf("\nOutput: Hello world!\n");
        }
        // system("pause");
        getch();
        system("cls");
    }
    return 0;
}