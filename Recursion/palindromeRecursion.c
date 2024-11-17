#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isPalindrome(char *str) {
	if (strlen(str) <= 1)
		return true;

	if (str[0] == str[strlen(str) - 1]) {
		strcpy(str, &str[1]);
		str[strlen(str) - 1] = '\0';
		return (isPalindrome(str));
	}

	return false;
}

int main() {
	char str[50], orig[50];
	printf("Enter string: ");
	gets(orig);
	strcpy(str, orig);
	if (isPalindrome(str)) {
		printf("\n%s is a Palindrome!", orig);
	}
}
