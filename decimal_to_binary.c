#include <stdio.h>
#include <stdlib.h>

void mybinary(int num) // my way of converting decimal to binary
{
	int binary[32];
	int count = 0;
	while (num > 0)
	{
		binary[count++] = num % 2;
		num /= 2;
	}

	for (int i = count - 1; i >= 0; i--)
	{
		printf("%d", binary[i]);
	}
}

int mytobinary(int num)
{
	int rem, sum = 0, place = 0, prod = 0;
	while (num != 0)
	{
		rem = num % 2;
		prod = rem * pow(10, place++);
		sum += prod;
		num = num / 2;
	}
	return sum;
}

int binary_rec(int num) // recursive way of converting decimal to binary
{

	if (num == 0)
	{

		return 0;
	}
	else
	{

		return ((num % 2) + 10 * binary_rec(num / 2));
	}
}

int main()
{
	int num, count = 0, binary[32];

	printf("Enter decimal: ");
	scanf("%d", &num);

	printf("\nmytobinary = %d", mytobinary(num));

	return 0;
}
