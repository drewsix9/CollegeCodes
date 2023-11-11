#include <stdio.h>
#include <stdlib.h>

int main() {
	
	int n;
	float arr[100];
	
	printf("Enter number of inputs: ");
	scanf("%d",&n); 
	
	printf("\nEnter inputs: ");
	for(int i=0;i<n;i++){		
		scanf("%f",&arr[i]);
	}
	
	float cast,num =2.2;
	cast = num - (int)num;
	
	return 0;
}
