#include <stdio.h>
#include <unistd.h>

int main(){
	
	int x,y,z, largest=0;
	
	printf("Input 3 numbers\n");
	sleep(3);
	printf("Input number 1\n");
	scanf("%d", &x);
	printf("Input number 2\n");
	scanf("%d", &y);
	printf("Input number 3\n");
	scanf("%d", &z);
	largest = x;
	if (y < largest){
		largest = y;
	}
	else if (z > largest){
		largest = z;
	}
	printf("The Largest mumber is:\t%d", largest);
	return 0;
}