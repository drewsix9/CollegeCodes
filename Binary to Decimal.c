#include <stdio.h>

int main()
{
	int num, j, rem, sum, prod, quot, power = 1;
	char repeat = 'n';

	do
	{
		printf("Enter a Binary Digit:\t");
		scanf("%d", &num);

		sum = 0;
		power = 1;

		for (;;)
		{
			quot = num / 10;
			rem = num % 10;
			prod = rem * power;
			sum = sum + prod;
			num = quot;
			power *= 2;

			if (quot == 0)
			{
				break;
			}
		}

		printf("%d\n", sum);

		printf("Do you want to repeat? (y/n)\n");
		scanf(" %c", &repeat);
	} while (repeat == 'y' || repeat == 'Y');

	return 0;
}
