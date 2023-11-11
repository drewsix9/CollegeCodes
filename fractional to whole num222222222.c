#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

	float num;
	float deci;

	printf("Enter float value: ");
	scanf("%f",&num);

	float temp = num - (int)num;

	int n=0;
	for(;;){
		temp = temp*10;
		if(temp - (int)temp == 0){
			break;
		}
	}

	printf("\n%.2f",temp);

	return 0;
}
