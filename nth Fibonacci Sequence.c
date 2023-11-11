#include <stdio.h>

int main() {

	int num, x=0, y=1, sum, j;
	printf("Enter the nth place of the fibonacci sequence: \t");
	scanf("%d", &num);
	
	printf("\t %d \t %d \t", x, y);

	for(j=2; j<num; j++) {
		sum = x + y;
		printf("%d\t", sum);
		x = y;
		y = sum;
	}
	return 0;
}