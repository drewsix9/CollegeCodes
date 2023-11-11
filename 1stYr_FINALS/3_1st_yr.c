#include <stdio.h>
#include <stdlib.h>

int main() {

	int n, arr[100], deci_arr[100];

	printf("Enter number of inputs: ");
	scanf("%d",&n);

	printf("\nEnter input(s): ");
	for(int i=0; i<n; i++) {
		scanf("%d",&arr[i]);
	}

	for(int i=0; i<n; i++) {
		int num = arr[i],quot,rem,prod;
		int power=1,sum=0;
		for(;;) {
			quot=num/10;
			rem=num%10;
			prod=rem*power;
			sum=sum+prod;
			power*=2;
			num=quot;
			if(quot==0) {
				break;
			}
		}
		deci_arr[i] = sum;
	}

	printf("\n Decimal: ");
	for(int i=0; i<n; i++) {
		printf("%d ",deci_arr[i]);
	}

	int factor,temp;
	for(int i=0; i<n; i++) {								//----
		factor=0;
		for(int k=2; k<deci_arr[i]; k++) {
			if(deci_arr[i] % k == 0) {
				factor++;
				break;
			}
			if(factor==0) {
				for(int j=i+1; j<n; j++) {					//----
					factor=0;
					for(int k=2; k<deci_arr[i]; k++) {
						if(deci_arr[j && i] % k == 0) {
							factor++;
							break;
						}
						if(factor==0) {
							if(deci_arr[i]>deci_arr[j]) {
								temp = arr[i];
								arr[i] = arr[j];
								arr[j] = temp;

								temp = deci_arr[i];
								deci_arr[i] = deci_arr[j];
								deci_arr[j] = temp;
							}
						}
					}
				}
			}
		}
	}
	printf("\n Output: ");
	for(int i=0; i<n; i++) {
		printf("%d ",arr[i]);
	}

	printf("\n Decimal: ");
	for(int i=0; i<n; i++) {
		printf("%d ",deci_arr[i]);
	}

	return 0;
}
