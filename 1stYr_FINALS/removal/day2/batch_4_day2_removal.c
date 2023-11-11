#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/* ask for whole numbers with no 0 as first digit, add up all digits niya sa kada number,
421 511 123 331 58 0
7    7   6   7  13

(context: 4+2+1=7, 5+1+1=7, ...)

if a prime number reappears ( in this case 7), dili maapil ang output sa original number.
if composite ang total, regardless if magbalik2, muappear gihapon ang original output.

in this situation, since multiple 7 and 7 is a prime man so ang output is:

123 58 ra
*/

bool isPrime(int num);

int main()
{

	int num, n = 0, arr[100], arr1[100], freq[100], arrS[100];

	printf("Enter inputs: ");
	do
	{
		scanf("%d", &num);
		if (num != 0)
		{
			arr[n] = num;
			n++;
		}
	} while (num != 0);

	(freq, -1, 100);
	// for(int i=0; i<100; i++) {
	// 	freq[i] = -1;
	// }

	for (int i = 0; i < n; i++)
	{
		int quot, rem, sum = 0, factor = 0, isPrime = 0, isComp = 0;
		num = arr[i];
		for (;;)
		{
			quot = num / 10;
			rem = num % 10;
			sum += rem;
			num = quot;
			if (quot == 0)
			{
				break;
			}
		}
		arrS[i] = sum;
	}

	int count;
	for (int i = 0; i < n; i++)
	{
		count = 1;
		for (int j = i + 1; j < n; j++)
		{

			if (arrS[i] == arrS[j])
			{
				count++;
				freq[j] = 0;
			}
		}
		if (freq[i] != 0)
		{
			freq[i] = count;
		}
	}

	printf("\nArray: ");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arrS[i]);
	}

	printf("\nFreq:  ");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", freq[i]);
	}

	printf("\n\nOutput: ");
	for (int i = 0; i < n; i++)
	{
		if ((isPrime(arrS[i]) && freq[i] == 1) || (isPrime(arrS[i]) == 0))
		{
			printf("%d ", arr[i]);
		}
	}
	return 0;
}

bool isPrime(int num)
{
	int factor = 0;
	for (int i = 2; i < num; i++)
	{
		if (num % i == 0)
		{
			return false;
		}
	}
	return true;
}