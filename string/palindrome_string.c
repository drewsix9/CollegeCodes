#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

	char string1[50];
	printf("Enter string:\t");
	gets(string1);

	int is_palindrome = 1;

	int len = strlen(string1);
	int mid = len / 2;

	for (int i = 0; i <= mid; i++)
	{
		if (string1[i] != string1[len - i - 1])
		{
			is_palindrome = 0;
			break;
		}
	}

	if (is_palindrome == 1)
	{
		printf("%s\n - is a palindrome", string1);
	}
	if (is_palindrome == 0)
	{
		printf("%s\n - is NOT palindrome", string1);
	}

	return 0;
}
