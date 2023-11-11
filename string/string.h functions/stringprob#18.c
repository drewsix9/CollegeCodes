/*
		Reverse piglatin
		Input: alpha bravo charlie delta echo
		Output: alphaay ravobay harliecay eltaday echoay
*/

#include <stdio.h>
#include <string.h>

int main()
{
	char str[100], vowels[] = "aeiouAEIOU";
	printf("Enter string: ");
	gets(str);

	printf("\nOutput:\n");
	char *word = strtok(str, " ");
	while (word != NULL)
	{
		int size = strlen(word);
		char *ptr = strchr(vowels, word[size - 3]);
		// ravobay
		if (ptr != NULL)
		{
			word[size - 3 + 1] = '\0';
			printf("%s ", word);
		}
		else
		{
			printf("%c", word[size - 3]);
			word[size - 3] = '\0';
			printf("%s ", word);
		}
		word = strtok(NULL, " ");
	}
	return 0;
}