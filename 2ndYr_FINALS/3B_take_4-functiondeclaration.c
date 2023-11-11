#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool hasDecimal(float num);
int decimal_whole(float num);
int count_decimalpoint_moved(int num);
int reversing(int num, int count);
float whole_to_decimal(int reversed, int count);

int main()
{
	int n = 0;
	float num, arr[100];

	printf("Enter inputs: ");

	do
	{
		scanf("%f", &num);
		if (num != 0)
		{
			arr[n] = num;
			n++;
		}
	} while (num != 0);

	printf("\n");
	for (int i = 0; i < n; i++)
	{
		printf("Input %d:\t", i);
		if (hasDecimal(arr[i]) == 1)
		{											   // check if whole number or not
			int decimal2whole = decimal_whole(arr[i]); // decimal in integer form
			printf("%d ", decimal2whole);

			int count = count_decimalpoint_moved(decimal2whole);
			int reversed = reversing(decimal2whole, count); // reversing
			printf("%d ", reversed);

			float whole2decimal = whole_to_decimal(reversed, count); // reversed in decimal form
			printf("%f ", whole2decimal);

			float final = (int)arr[i] + whole2decimal;
			printf("%f ", final);
			printf("\n");
		}
		else
		{
			printf("%f ", arr[i]);
			printf("\n");
		}
	}
	return 0;
}

bool hasDecimal(float num)
{
	if (num - (int)num == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

int decimal_whole(float num)
{
	int count = 0;
	float deci = num;
	for (;;)
	{
		deci = deci * 10;
		count++;
		if (deci - (int)deci == 0)
		{
			break;
		}
	}
	return (int)(deci - ((int)num * pow(10, count)));
}

int count_decimalpoint_moved(int num)
{
	int quot, rem;
	int count = 0;
	for (;;)
	{
		quot = num / 10;
		rem = num % 10;
		count++;
		num = quot;
		if (quot == 0)
		{
			break;
		}
	}
	return count;
}

int reversing(int num, int count)
{
	int quot, rem, sum = 0, prod = 0, temp = num;
	for (;;)
	{
		quot = temp / 10;
		rem = temp % 10;
		prod = rem * pow(10, count - 1);
		count--;
		sum = sum + prod;
		temp = quot;
		if (quot == 0)
		{
			break;
		}
	}
	return sum;
}

float whole_to_decimal(int reversed, int count)
{
	return reversed * pow(0.10, count);
}