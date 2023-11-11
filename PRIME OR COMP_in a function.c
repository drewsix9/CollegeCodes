#include <stdio.h>
#include <conio.h>

int checkprime(int num);


int main (void) {
	int num, factor=0, j;

	printf("This program determines if a number is Prime or Composite.\nEnter a Number: \n");
	scanf("%d", &num);

//	for (j=2; j<num; j++) {
//
//		if (num%j == 0) {
//
//			factor++;
//		}
//	}

	if (checkprime(num) == 0) {

		printf("\n%d is a PRIME number\n", num);

	} else {

		printf("\n%d is a COMPOSITE number\n", num);
	}
	return 0;
}

int checkprime(int num){
	int factor=0;
	
	for(int i=2;i<num;i++){
		if(num%i==0){
			factor++;
		}
	}
	return factor;
}