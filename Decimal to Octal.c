#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int mytoOctal(int num)
{
	int temp = num, digits = 0;
	while (temp > 0)
	{
		digits++;
		temp /= 10;
	}

	int power = 0, sum = 0, rem = 0, prod = 0;
	while (num > 0)
	{
		rem = num % 8;
		prod = rem * pow(10, power++);
		sum = sum + prod;
		num /= 8;
	}
	return sum;
}

int main()
{
	int num, n = 0, arr[100];

	printf("Enter decimal to convert to octal: ");
	scanf("%d", &num);
	int orig_num = num;

	int quot, rem;
	for (;;)
	{
		quot = num / 8;
		rem = num % 8;
		arr[n] = rem;
		n++;
		num = quot;
		if (quot == 0)
		{
			break;
		}
	}

	for (int i = (n - 1); i >= 0; i--)
	{
		printf("%d", arr[i]);
	}

	int octal = mytoOctal(orig_num);

	printf("\nMy Octal way: %d", octal);

	return 0;
}
