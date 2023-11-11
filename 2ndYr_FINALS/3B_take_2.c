#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

	float num, arr[100];
	int n=0,count,digit;

	printf("Enter inputs: ");
	do {
		scanf("%f",&num);
		if(num!=0) {
			arr[n]=num;
			n++;
		}
	} while(num!=0);

	for(int i=0; i<n; i++) {
		printf("\n\n");
		count=0;
		if(arr[i] - (int)arr[i] !=0) {
			float deci = arr[i];
			for(;;) {
				deci = deci * (float)10;
				count++;
				if(deci - (int)deci == 0) {
					break;						//1.32
				}						//deci = 132.
			}							//132 - 1*10^2	= 32
			int intDeci = (int)((deci - (int)arr[i] * pow(10,count)));
//			printf("count=%d ",count);
			printf("%d ",intDeci);
			int temp = intDeci;

			int intDeciFact = intDeci + (int)((int)arr[i] * pow(10,count));

//			printf("%d ",intDeciFact);
			int temp1 = intDeciFact;
			int quot,rem,sum,prod,power=count-1;	//2.234  2234-2000 234 = 432
			for(int o=1; o<=count; o++) {	
				quot = temp1/10;
				rem = temp1%10;
				prod = rem * pow(10,power);
				sum = sum + prod;
				power -=1;
				temp1 = quot;
			}
//			printf("%d ",sum);

			float deciSum = (float)sum;
			float final = (int)arr[i] + deciSum * pow(0.10,count); //moves the decimal point
			printf("%f ",final);
		} else {
			printf("%f ",arr[i]);
		}
	}
	return 0;
}
