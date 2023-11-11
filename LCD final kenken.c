#include <stdio.h>
#include <stdlib.h>

int main()
{

	int num1, num2, lcd;

	printf("Enter num1: ");
	scanf("%d", &num1);
	printf("Enter num2: ");
	scanf("%d", &num2);

	if (num1 > num2)
	{
		lcd = num2;
	}
	else
	{
		lcd = num1;
	}

	// starting lcd must be the smallest
	for (;;)
	{
		if (lcd % num2 == 0 && lcd % num1 == 0)
		{
			printf("%d", lcd);
			break;
		}
		lcd++;
	}

	return 0;
}
