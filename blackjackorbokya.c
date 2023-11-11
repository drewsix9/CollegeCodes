// black jack = draw 3 cards, alas (1) will only be 11 if total is less than 21 else it is only 1
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int total, num1, num2, num3;
	printf("Enter 3 card \nEnter 1st card: ");
	scanf("%d", &num1);
	printf("Enter 2nd card: ");
	scanf("%d", &num2);
	printf("Enter 3rd card: ");
	scanf("%d", &num3);

	total = num1 + num2 + num3;

	if ((total < 21) && (num1 == 1 || num2 == 1 || num3 == 1))
	{
		total = total + 10;
		if (total > 21)
		{
			total = total - 10;
		}
	}
	if (total == 21)
	{
		printf("\n %d Black Jack! \n", total);
	}
	else
	{
		printf("\n %d Bokya! \n", total);
	}
	return 0;
}
