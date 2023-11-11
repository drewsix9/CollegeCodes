// ask for float n numbers, 1,3,6,7
// get prime and comp
// if prime print in binary

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void deci_to_bi(float num);

int main()
{

	float num;
	int input;
	int factor = 0;

	printf("Enter how many inputs:\t");
	scanf("%d", &input);
	for (int i = 1; i <= input; i++)
	{

		factor = 0;
		printf("Enter num:\t");
		scanf("%f", &num);

		for (int j = 2; j < (int)num; j++)
		{

			if ((int)num % j == 0)
			{
				factor++;
			}
		}

		float temp = num - (int)num;
		//		int tempn= num - temp;

		if (factor == 0)
		{ // PRIME

			if (temp != 0)
			{

				printf("\n%.2f\n\n", num);
			}
			int quot, rem;

			if (temp == 0)
			{

				printf("\n");

				deci_to_bi(num);

				printf("\n\n");
			}
		}
		else
		{ // COMPOSITE
			printf("\n%.2f\n\n", num);
		}
	}

	return 0;
}

void deci_to_bi(float num)
{

	int temp = (int)num;
	int binary[32];
	int count = 0;

	while (temp > 0)
	{
		binary[count] = temp % 2;
		temp /= 2;
		count++;
	}

	int prod = 0, sum = 0, power = count - 1;
	for (int i = count - 1; i >= 0; i--)
	{
		// printf("%d", binary[i]);
		prod = binary[i] * pow(10, power);
		power--;
		sum += prod;
	}
	printf("%d\n", sum);
}
