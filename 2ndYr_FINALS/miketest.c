#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*enter float value inputs until the user inputs '0'. If the decimal part of the float value is prime, print its original float value.

illustration:

Input: 2.11 2.14 2.17 2.19 0

Output: 2.11 2.17 2.19
*/

int main() {

	float arr[100],num;
	int n=0;

	printf("Enter inputs: ");

	do {
		scanf("%f",&num);
		if(num!=0) {
			arr[n] = num;
			n++;
		}
	} while(num!=0);

	for(int i=0; i<n; i++) {
		float deci = arr[i];
		int count=0;
		
		for(;;){
			deci = deci*10;
			count++;
			if(deci - (int)deci == 0){
				break;
			}
		}
		int converted = deci - ((int)arr[i]*pow(10,count));
//		printf("converted = %d, ",converted);
		
		int factor=0;
		for(int j=2;j<converted;j++){	// checking if prime
			if(converted % j == 0){
				factor++;
				break;
			}
		}
		if(factor==0){
			printf("%f ",arr[i]);
		}
	}
	return 0;
}
