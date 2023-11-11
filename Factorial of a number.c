#include <stdio.h>

int main(){
	
	int num, j, factorial=1;
	
	printf("Enter a number to be in factorial:\t");
	scanf("%d", &num);
	
	for(j=2; j<=num; j++){
		factorial = factorial * j;
	
	}
	printf("%d", factorial);
	return 0;
}