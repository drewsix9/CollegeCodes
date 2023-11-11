#include <stdio.h>
#include <string.h>

int main()
{
	printf("Enter strings:\n");
	char buffer[50];
	char str[100][100];

	int n = 0;
	while (fgets(buffer, 50, stdin) && buffer[0] != '\n')
	{
		strcpy(str[n], buffer);
		str[n][strlen(str[n]) - 1] = '\0';
		n++;
	}

	int Highest = 0;
	char HighestUniq[50];
	for (int i = 0; i < n; i++)
	{
		char unique[strlen(str[i])];
		int counted = 0;
		for (int j = 0; j < strlen(str[i]); j++)
		{
			int isCounted = 0;
			for (int k = 0; k < counted; k++)
			{
				if (str[i][j] == unique[k])
				{
					isCounted = 1;
				}
			}
			if (isCounted == 1)
				continue;

			unique[counted++] = str[i][j];
		}
		unique[counted++] = '\0';
		int size = strlen(unique);
		if (size > Highest)
		{
			Highest = size;
			strcpy(HighestUniq, str[i]);
		}
	}

	printf("\nHighest number of unique characters is \'%s\', which has %d unique characters", HighestUniq, Highest);
}