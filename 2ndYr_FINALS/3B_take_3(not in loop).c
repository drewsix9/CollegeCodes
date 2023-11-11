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
	for(;;) {		// moving the decimal point
		deci = deci * 10;
		n++;
		if(deci - (int)deci == 0) {
			break;
		}
	}

	int final = (int)(deci - ((int)num*pow(10,n)));
//	printf("\n%d",final);

	int temp = final,j=0;
	int arr[100];
	int quot,rem;
	for(;;) {		//reversing
		quot=temp/10;
		rem=temp%10;
		arr[j] = rem;
		j++;
		temp = quot;
		if(quot==0) {
			break;
		}
	}
//	printf("\n");
//	for(int i=0; i<n; i++) {
//		printf("arr[%d]=%d\n",i,arr[i]);
//	}

//	printf("n=%d\nj=%d",n,j);


	int zero = 0,sum=0,prod=0;
	for(int i=j; i>0; i--) {
		prod = arr[zero] * pow(10,i-1);
		sum=sum+prod;
		zero++;
	}
//	printf("sum = %d",sum);

	float final2 = ((int)num) + sum * pow(0.10,n);
	printf("\n\nfinal2 = %f",final2);
	return 0;
}
