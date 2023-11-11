#include <stdio.h>

int main(){
	
	int temp;
	
	printf("What is your body temperature?\t");
	scanf("%d", &temp);
	
	switch(temp>=36.5 && temp<=37.5){
		case 1:
			printf("\nYour body temperature is NORMAL");
			break;
		case 2:
			printf("\nYour body temperatur is NOT NORMAL");
			break;	
	}
	return 0;
}