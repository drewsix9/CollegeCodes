#include <stdio.h>
#include <stdlib.h>

int main() {

	int input,n=0,binary_arr[100];

	printf("Enter binary inputs: ");

	do {
		scanf("%d",&input);
		if(input !=0 ) {
			binary_arr[n] = input;
			n++;
		}
	} while(input !=0);

	//storing the decimal equvalent of the entered binary inputs
	int quot,rem,power=1,decimal_arr[100],temp,prod,sum;
	for(int i=0; i<n; i++) {
		temp = binary_arr[i];
		sum=0;
		power=1;
		for(;;) {
			quot=temp/10;
			rem=temp%10;
			prod=rem*power;
			sum+=prod;
			temp=quot;
			power*=2;
			if(quot==0) {
				break;
			}
		}
		decimal_arr[i] = sum;
	}

	printf("\nBefore:\n");
	for(int i=0; i<n; i++) {
		printf("%4d ",binary_arr[i]);
	}
	printf("\n");
	for(int i=0; i<n; i++) {
		printf("%4d ",decimal_arr[i]);
	}

	//sorting in ascending order
	int temp1;
	for(int i=0; i<n; i++) {
		for(int j=i+1; j<n; j++) {
			if(decimal_arr[i] > decimal_arr[j]) {
				//swap the decimals
				temp1 = decimal_arr[i];
				decimal_arr[i] = decimal_arr[j];
				decimal_arr[j] = temp1;
				//swap the binaries
				temp1 = binary_arr[i];
				binary_arr[i] = binary_arr[j];
				binary_arr[j] = temp1;
			}
		}
	}

	printf("\n\nAfter:\n");
	for(int i=0; i<n; i++) {
		printf("%4d ",binary_arr[i]);
	}
	printf("\n");
	for(int i=0; i<n; i++) {
		printf("%4d ",decimal_arr[i]);
	}

	return 0;
}
