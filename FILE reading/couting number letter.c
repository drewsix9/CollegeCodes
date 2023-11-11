#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
	FILE *fptr_in;
	fptr_in = fopen("abstract.txt", "r");

	if (fptr_in == NULL)
	{
		printf("Error! @ IN");
		return 1;
	}

	int freq[26];
	for (int i = 0; i < 26; i++)
	{
		freq[i] = 0;
	}

	char c;
	char str[500];
	while (fgets(str, 500, fptr_in) != NULL)
	{
		int size = strlen(str);
		for (int i = 0; i < size; i++)
		{
			c = tolower(str[i]);
			if (isalpha(c))
			{
				freq[c - 'a']++;
			}
		}
	}
	
	FILE *fptr_out = fopen("output.txt", "w");

	if (fptr_out == NULL)
	{
		printf("Error! @ OUT");
		return 1;
	}

	for (int i = 0; i < 26; i++)
	{
		fprintf(fptr_out, "%c => %d\n", 'a' + i, freq[i]);
	}

	fclose(fptr_in);
	fclose(fptr_out);

	return 0;
}