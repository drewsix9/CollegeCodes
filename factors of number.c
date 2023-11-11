//finding the GCF of two numbers

#include <stdio.h>
#include <stdlib.h>

int main() {


	int num1,num2,rem=0,input;

//	printf("\nEnter num2:\t");
//	scanf("%d",&num2);

	printf("\nEnter how many inputs:\t");
	scanf("%d",&input);

	for (int k=1; k<=input; k++) {

		printf("\n\nEnter num:\t");
		scanf("%d",&num1);

		printf("\nFactors of %d:\n",num1);
		for(int i=2; i<=num1; i++) {

			rem=num1%i;

			if (rem==0) {
				printf("%d ",i);
			}
		}
	}

//	printf("\nFactors of %d:\n",num2);
//	for(int j=2; j<=num2; j++) {
//
//		rem=num2%j;
//
//		if (rem==0) {
//			printf ("%d ",j);
//		}
//	}

	return 0;
}
