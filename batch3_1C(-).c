#include <stdio.h>
#include <stdlib.h>

//Ngayu ug inputs , then ask for the number of digit,
//I print Ang whole number and also Ang number nga dli the same
//Ang number of digits sa gi input nimo nga number.
//I ban Ang dli whole num and Ang number of digit nga the same sa input num of dig.



void digits_to_array (int array [], int num, int dig);

int not_same_to_dig (int array[], int dig);


int main() {

	int n,num,dig,arr[20];

	printf("Enter how many inputs:\t");
	scanf("%d",&n);

	for (int i=1; i<=n; i++) {
		printf("\nEnter input %d:\t",i);
		scanf("%d",&num);

		printf("\nEnter how many digits:\t");
		scanf("%d",&dig);

		digits_to_array (arr, num, dig);

		printf("\nnumber: %d\nnot same to no. of digits: %d\n",num,not_same_to_dig(arr,dig));
	}
	return 0;
}


void digits_to_array (int array [], int num, int dig) {

	int temp = num;

	for (int i = dig-1; i >= 0 ; i--) {
		array[i] = temp % 10;
		temp /= 10;
	}

	//for (int j=0; j<dig; j++) {
	//	printf("array [%d] = %d\n",j,array[j]);
	//}
}

int not_same_to_dig (int array[], int dig) {
	int temp=0;

	for (int i = 0; i<dig; i++) {
		if(array[i] != dig) {
			temp = temp * 10 + array[i];
		}
	}
	return temp;
}