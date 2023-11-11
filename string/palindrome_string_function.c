#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isPalindrome(char *string);

int main()
{

	int n;

	printf("Enter how many inputs:\t");
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{

		char string1[50];

		printf("\nEnter string:\t");
		scanf("%s", &string1);

		if (isPalindrome(string1))
		{
			printf("\n%s is a Palindrome\n", string1);
		}
		else
		{
			printf("\n%s is not a Palindrome\n", string1);
		}
	}
	return 0;
}

bool isPalindrome(char string[])
{
	int len = strlen(string);
	int mid = len / 2;

	for (int i = 0; i <= mid; i++)
	{
		if (string[i] != string[len - i - 1])
			return false;
	}
	return true;
}
