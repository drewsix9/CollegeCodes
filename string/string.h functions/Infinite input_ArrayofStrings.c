#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char str[100][100];
	char buffer[20];
	int n = 0;
	while ((fgets(buffer, 20, stdin) != NULL) && buffer[0] != '\n')
	{
		strcpy(str[n], buffer);
		str[n][strlen(str[n]) - 1] = 0;
		n++;
	}

	printf("\nOuput:\n\n");
	for (int i = 0; i < n; i++)
	{
		printf("%s\n", str[i]);
	}
}
