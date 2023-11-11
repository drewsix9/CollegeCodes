#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

	float num;
	float deci;

	printf("Enter float value: ");
	scanf("%f",&num);

	deci = num;

	int n=0;
	for(;;) {
		deci = deci * 10;
		n++;
		if(deci - (int)deci == 0) {
			break;
		}
	}

	int final = (int)(deci - ((int)num*pow(10,n)));
	
	printf("\n%d",final);

	return 0;
}
