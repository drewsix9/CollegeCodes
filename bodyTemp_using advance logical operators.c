#include <stdio.h>

int main(){
	
	int temp;
	
	printf("What is your body temperature?\t");
	scanf("%d", &temp);
	
	if(temp>=36.5 && temp<=37.5){
		
		printf("\nYour body temperature is NORMAL");
	}
	else{
		
		printf("\nYour body temperatur is NOT NORMAL");
	}
	return 0;
}