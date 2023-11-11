#include <stdio.h>

int main ()
{
	int counter, num;
	
	printf("Count from 1 to __?\n");
	scanf("%d", &num);
	
	for(counter=1;counter<=num;counter++)
	{
		printf("%d ", counter);
	}
	return 0;
}