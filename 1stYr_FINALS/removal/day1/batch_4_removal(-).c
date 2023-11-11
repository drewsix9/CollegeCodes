#include <stdio.h>
#include <stdlib.h>

/*
kuan to ang problem kuhag input like
2.543 45 64.42 645 0

then ang buhaton sa program kay icheck ang mga numbers
kung prime bah ang whole number nya composite ang decimal
if composite ang decimal then iprint ang number sa output
*/

int main() {

	int n;
	float num, arr[100];

	printf("Enter input(s): ");
	do {
		scanf("%f",&num);
		if(num!=0) {
			arr[n] = num;
			n++;
		}
	} while(num!=0);

	float deci;
	int factor,intDeci;
	for(int i=0;i<n;i++){
		
		deci = arr[i] - (int)arr[i];	// Casting
		
		for(;;){
			deci = deci*10;
			if(deci - (int)deci == 0){
				break;
			}
		}
		
		intDeci = (int)deci;	// Casting
		printf("Decimal:%d ",intDeci);
		
		factor=0;
		for(int j=2;j<intDeci;j++){
			if(intDeci % j == 0){
				factor++;
				break;
			}
		}
		if(factor!=0){	//if composite
			printf("%.5f ",arr[i]);
		}
	}

	return 0;
}
