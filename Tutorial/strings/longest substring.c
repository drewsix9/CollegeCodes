#include <stdio.h>
#include <string.h>

// abcddefffg

int main()
{
	char str[100];
	printf("Enter string: ");
	gets(str);

	int size = strlen(str);
	int i = 0;
	int j = 0;
	int max = 0;
	int count = 0;
	char max_str[50];

	while(i < size)
	{
		j=i;
		while(j < size-1)
		{
			if(str[j]==str[j+1])
			{
				count = j-i+1;
				if(count > max)
				{
					max=count;
					strncpy(max_str, str+i,max);
					break;
				}
			}
			j++;
		}
		i = j+1;
	}
	printf("Output = %d %s", max,max_str);

	return 0;
}