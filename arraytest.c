#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(char[]);

int main()
{

	// check if palindrome

	char string[100];
	printf("Enter a string: ");
	scanf("%s", string);

	if (isPalindrome(string))
	{
		printf("%s is a Palindrome", string);
	}
	else
	{
		printf("%s is not a Palindrome", string);
	}
	return 0;
}

bool isPalindrome(char str[])
{
	int length = strlen(str);

	for (int i = 0; i < length / 2; i++)
	{
		if (str[i] != str[length - i - 1])
		{
			return false;
		}
	}
	return true;
}
