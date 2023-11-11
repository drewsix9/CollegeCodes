#include <stdio.h>
#include <string.h>

int CheckIftobeReversed(char *str)
{
	char vowels[] = "aeiouAEIOU";
	char temp[sizeof(str)];
	strcpy(temp, str);

	char *ptr = strpbrk(temp, vowels);
	while (ptr != NULL)
	{
		if (*ptr == *(ptr + 1) && *ptr == *(ptr + 2))
		{
			return 0;
		}
		else if (*ptr == *(ptr + 1))
		{
			return 1;
		}
		strcpy(temp, ptr + 1);
		ptr = strpbrk(temp, vowels);
	}
	return 0;
}

int main()
{
	char buffer[100];
	printf("Enter string: ");
	fgets(buffer, 100, stdin);
	buffer[strlen(buffer) - 1] = '\0';

	printf("\nOutput: ");
	char *ptr = strtok(buffer, " \0\n");
	while (ptr != NULL)
	{
		if (CheckIftobeReversed(ptr) == 1)
		{
			strrev(ptr);
			printf("%s ", ptr);
		}
		else
		{
			printf("%s ", ptr);
		}
		ptr = strtok(NULL, " \0\n");
	}

	return 0;
}