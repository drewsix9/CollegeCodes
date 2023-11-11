#include <stdio.h>
#include <stdlib.h>

int main()
{

	int num1, num2, num3, total1, total2;

	printf("Enter 3 Card Numbers\n\nEnter 1st Card:\t");
	scanf("%d", &num1);
	printf("Enter 2nd Card:\t");
	scanf("%d", &num2);
	printf("Enter 3rd Card:\t");
	scanf("%d", &num3);

	if ((num1 >= 1 && num1 <= 10) && (num2 >= 1 && num2 <= 10) && (num3 >= 1 && num3 <= 10))
	{

		total1 = num1 + num2 + num3;

		if (total1 >= 21)
		{
			if (num1 == 1)
			{
				num1 = 1;
			}
			if (num2 == 1)
			{
				num2 = 1;
			}
			if (num3 == 1)
			{
				num3 = 1;
			}
		}
		if (total1 < 21)
		{
			if (num1 == 1)
			{
				num1 = 11;
			}
			if (num2 == 1)
			{
				num2 = 11;
			}
			if (num3 == 1)
			{
				num3 = 11;
			}
		}

		total2 = num1 + num2 + num3;
		if (total2 == 21)
		{
			printf("\n %d BLACK JACK! \n", total2);
		}
		else
		{
			printf("\n %d Bokya", total2);
		}
	}
	else
	{
		printf("ERROR");
	}
	return 0;
}
