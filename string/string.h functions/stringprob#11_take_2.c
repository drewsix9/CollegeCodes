#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char str[100];
	printf("Enter string: ");
	fgets(str, 100, stdin);
	str[strlen(str) - 1] = '\0';

	int length = strlen(str);
	int count = 0;
	int max = 0;
	char max_word[50];

	char not_word[] = " .,?!\n\t";

	char *ptr = strtok(str, not_word);
	while (ptr != NULL)
	{
		count = strlen(ptr);
		if (count > max)
		{
			max = count;
			strcpy(max_word, ptr);
			max_word[strlen(max_word)] = '\0';
		}
		ptr = strtok(NULL, not_word);
	}

	printf("\nOutput: %s", max_word);

	return 0;
}