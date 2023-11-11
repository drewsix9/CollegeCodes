#include <stdio.h>
#include <stdlib.h>

int main() {
	
	int array[5];
	int num;
	
	for(int i=0;i<5;i++){ //storing of each input into an array
		printf("Enter array [%d]: ",i);
		scanf("%d",&num);
		array[i]=num;
	}
	
	for(int i=0;i<20;i++){
		printf("array[%d] = %d\n",i,array[i]);
	}
	return 0;
}
