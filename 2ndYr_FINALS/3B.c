#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

	int n = 0;
	float arr[100], num;

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

	float cast, deci;
	int nn, fract2whole;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] - (int)arr[i] != 0)
		{
			deci = arr[i];
			nn = 0;
			for (;;)
			{
				deci = deci * 10;
				nn++;
				if (deci - (int)deci == 0)
				{
					break;
				}
			}
			fract2whole = (int)((deci) - ((int)arr[i] * pow(10, nn))); // stores the fraction part converted to whole num.
			int temp = fract2whole;
			int quot, rem, count = 0;
			printf("fract2whole = %d ", fract2whole);

			for (;;)
			{ // counts how many digits
				quot = temp / 10;
				rem = temp % 10;
				temp = quot;
				count++;
				if (quot == 0)
				{
					break;
				}
			}
			//			printf("count = %d ",count);

			int temp1 = fract2whole;
			int power = -1;
			float prod, sum = 0;
			for (;;)
			{ // reverses and converts back into decimal part
				quot = temp1 / 10;
				rem = temp1 % 10;
				prod = rem * pow(10, power);
				sum += prod;
				power -= 1;
				temp1 = quot;
				if (quot == 0)
				{
					break;
				}
			}
			//			printf("reversed = %f ",sum);
			arr[i] = (int)arr[i] + sum;
			printf("%f ", arr[i]);
		}
		else
		{
			printf("%.0f ", arr[i]);
		}
	}

	return 0;
}
