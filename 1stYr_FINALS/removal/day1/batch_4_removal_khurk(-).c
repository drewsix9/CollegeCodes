#include <stdio.h>
#include <stdlib.h>

int main()
{
	float inp[999], dec;
	int n = 0, sWhole = 0, sDec = 0, count, isP = 0, isC = 0, temp, decN;
	for (int i = 0;; i++)
	{
		scanf("%f", &inp[i]);
		n++;
		if (inp[i] == 0)
		{
			break;
		}
	}
	for (int j = 0; j < n - 1; j++)
	{
		if (inp[j] - (int)inp[j] != 0)
		{ // has decimal
			temp = (int)inp[j];
			isP = 0;
			isC = 0;
			sWhole = 0;
			sDec = 0;
			for (;;)
			{
				sWhole = sWhole + temp % 10;
				temp = temp / 10;
				if (temp == 0)
				{
					break;
				}
			}
			count = 0;
			for (int l = 2; l < sWhole; l++)
			{
				if (sWhole % l == 0)
				{
					count++;
				}
			}
			if (count == 0)
			{
				isP = 1;
			}

			dec = inp[j] - (int)inp[j];
			for (;;)
			{
				dec = dec * 10;
				if (dec - (int)dec == 0)
				{
					break;
				}
			}
			decN = (int)dec;
			for (;;)
			{
				sDec = sDec + decN % 10;
				decN = decN / 10;
				if (decN == 0)
				{
					break;
				}
			}

			count = 0;
			for (int m = 2; m < sDec; m++)
			{
				if (sDec % m == 0)
				{
					count++;
				}
			}
			if (count != 0)
			{
				isC = 1;
			}
			if (isP == 1 && isC == 1)
			{
				printf("%.5f ", inp[j]);
			}
		}
	}
	return 0;
}