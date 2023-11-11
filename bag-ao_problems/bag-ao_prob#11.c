#include <stdio.h>
#include <stdlib.h>

void reset(int new_nume[], int new_deno[])
{
    for (int i = 0; new_nume[i] != NULL && new_deno[i] != NULL; i++)
    {
        new_nume[i] = NULL;
        new_deno[i] = NULL;
    }
}

int AddFractions(int nume[], int deno[], int frac_size, int new_nume[], int new_deno[])
{
    int newfrac_size = 0;
    for (int i = 0; i < frac_size; i += 2)
    {
        int j = i + 1;
        // if similar fractions
        if (deno[i] == deno[j])
        {
            new_deno[newfrac_size] = deno[i];
            new_nume[newfrac_size] = nume[i] + nume[j];
        }
        else
        {
            new_deno[newfrac_size] = deno[i] * deno[j];
            new_nume[newfrac_size] = (nume[i] * deno[j]) + (nume[j] * deno[i]);
        }
        newfrac_size++;
    }
    return newfrac_size;
}

int SubtractFractions(int nume[], int deno[], int frac_size, int new_nume[], int new_deno[])
{
    int newfrac_size = 0;
    for (int i = 0; i < frac_size; i += 2)
    {
        int j = i + 1;
        // if similar fractions
        if (deno[i] == deno[j])
        {
            new_deno[newfrac_size] = deno[i];
            new_nume[newfrac_size] = nume[i] - nume[j];
        }
        else
        {
            new_deno[newfrac_size] = deno[i] * deno[j];
            new_nume[newfrac_size] = (nume[i] * deno[j]) - (nume[j] * deno[i]);
        }
        newfrac_size++;
    }
    return newfrac_size;
}

int MultiplyFractions(int nume[], int deno[], int frac_size, int new_nume[], int new_deno[])
{
    int newfrac_size = 0;
    for (int i = 0; i < frac_size; i += 2)
    {
        int j = i + 1;
        new_nume[newfrac_size] = nume[i] * nume[j];
        new_deno[newfrac_size] = deno[i] * deno[j];
        newfrac_size++;
    }
    return newfrac_size;
}

int DividingFractions(int nume[], int deno[], int frac_size, int new_nume[], int new_deno[])
{
    int newfrac_size = 0;
    for (int i = 0; i < frac_size; i += 2)
    {
        int j = i + 1;
        new_nume[newfrac_size] = nume[i] * deno[j];
        new_deno[newfrac_size] = deno[i] * nume[j];
        newfrac_size++;
    }
    return newfrac_size;
}

int inputfractions(int nume[], int deno[])
{
    int temp, nume_size = 0;
    printf("Enter Numerators: ");
    do
    {
        scanf("%d", &temp);
        if (temp != 0)
        {
            nume[nume_size++] = temp;
        }
    } while (temp != 0);

    int deno_size = 0;
    printf("Enter Denominators: ");
    do
    {
        scanf("%d", &temp);
        if (temp != 0)
        {
            deno[deno_size++] = temp;
        }
    } while (temp != 0);
    return deno_size;
}

void simplifying(int new_nume[], int new_deno[], int newfrac_size)
{
    for (int i = 0; i < newfrac_size; i++)
    {
        int temp_nume = new_nume[i];
        int temp_deno = new_deno[i];
        int larger = 0, quot = 0, rem = 0, gcf = 0;

        if (temp_nume > temp_deno) // finding GCF
        {
            larger = temp_nume;
            for (;;)
            {
                quot = larger / temp_deno;
                rem = larger % temp_deno;
                if (rem == 0)
                {
                    gcf = temp_deno;
                    break;
                }
                larger = temp_deno;
                temp_deno = rem;
            }
        }
        else
        {
            larger = temp_deno;
            for (;;)
            {
                quot = larger / temp_nume;
                rem = larger % temp_nume;
                if (rem == 0)
                {
                    gcf = temp_nume;
                    break;
                }
                larger = temp_nume;
                temp_nume = rem;
            }
        }
        new_nume[i] = new_nume[i] / gcf;
        new_deno[i] = new_deno[i] / gcf;
    }
}

int main()
{
    int nume[100], deno[100], choice, new_nume[100], new_deno[100], stop = 0, temp;
    int frac_size = inputfractions(nume, deno);

    while (stop != 1)
    {
        printf("Your inputs are:\n\n");
        for (int i = 0; i < frac_size; i++)
        {
            printf("%d/%d\n", nume[i], deno[i]);
        }
        printf("\nChoice [1]: Addition\n");
        printf("Choice [2]: Subtract\n");
        printf("Choice [3]: Multiplication\n");
        printf("Choice [4]: Division\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            // Add
            printf("\nAdding:\t");
            for (int i = 0; i < frac_size; i += 2)
            {
                int j = i + 1;
                printf("%d/%d + %d/%d", nume[i], deno[i], nume[j], deno[j]);
                if (i != frac_size - 2)
                {
                    printf(" and ");
                }
            }
            reset(new_nume, new_deno);
            int newfrac_size = AddFractions(nume, deno, frac_size, new_nume, new_deno);
            simplifying(new_nume, new_deno, newfrac_size);
            printf("\n\nOutput: \n");
            for (int i = 0; i < newfrac_size; i++)
            {
                printf("%d/%d\n", new_nume[i], new_deno[i]);
            }
        }
        else if (choice == 2)
        {
            // Subtract
            printf("\nSubtracting:\t");
            for (int i = 0; i < frac_size; i += 2)
            {
                int j = i + 1;
                printf("%d/%d - %d/%d", nume[i], deno[i], nume[j], deno[j]);
                if (i != frac_size - 2)
                {
                    printf(" and ");
                }
            }
            reset(new_nume, new_deno);
            int newfrac_size = SubtractFractions(nume, deno, frac_size, new_nume, new_deno);
            simplifying(new_nume, new_deno, newfrac_size);
            printf("\n\nOutput: \n");
            for (int i = 0; i < newfrac_size; i++)
            {
                printf("%d/%d\n", new_nume[i], new_deno[i]);
            }
        }
        else if (choice == 3)
        {
            // Multiple
            printf("\nMultiplying:\t");
            for (int i = 0; i < frac_size; i += 2)
            {
                int j = i + 1;
                printf("%d/%d * %d/%d", nume[i], deno[i], nume[j], deno[j]);
                if (i != frac_size - 2)
                {
                    printf(" and ");
                }
            }
            reset(new_nume, new_deno);
            int newfrac_size = MultiplyFractions(nume, deno, frac_size, new_nume, new_deno);
            simplifying(new_nume, new_deno, newfrac_size);
            printf("\n\nOutput: \n");
            for (int i = 0; i < newfrac_size; i++)
            {
                printf("%d/%d\n", new_nume[i], new_deno[i]);
            }
        }
        else if (choice == 4)
        {
            // Divide
            printf("\nDividing:\t");
            for (int i = 0; i < frac_size; i += 2)
            {
                int j = i + 1;
                printf("%d/%d / %d/%d", nume[i], deno[i], nume[j], deno[j]);
                if (i != frac_size - 2)
                {
                    printf(" and ");
                }
            }
            reset(new_nume, new_deno);
            int newfrac_size = DividingFractions(nume, deno, frac_size, new_nume, new_deno);
            simplifying(new_nume, new_deno, newfrac_size);
            printf("\n\nOutput: \n");
            for (int i = 0; i < newfrac_size; i++)
            {
                printf("%d/%d\n", new_nume[i], new_deno[i]);
            }
        }
        printf("\nDo you want to stop? (1/0): ");

        scanf("%d", &temp);
        if (temp == 1)
        {
            stop = 1;
        }

        system("cls");
    }

    return 0;
}
