#include <stdio.h>
#include <stdlib.h>
/*You are given a one-dimensional array of integers,
where each element represents a binary number.
Your task is to convert each binary number to decimal,
store the decimal values in a new array, and then sort
the new array in ascending order using the bubble sort algorithm.
Finally, you should determine the frequency of a given element in the sorted array.*/

/*
Input:
Number of Inputs: 5
Original binary array: [1101, 1010, 1001, 1111, 1100] // 1101 1010 1001 1111 1100
Element to find frequency of: 1101

Output:
Decimal array after conversion: [13, 10, 9, 15, 12]
Sorted decimal array: [9, 10, 12, 13, 15]
Frequency of element 1101 (decimal 13) in the sorted array: 1
*/

int main() {

	int n, binary_arr[100],find_freq,decimal_arr[100];

	printf("Enter how many inputs: ");
	scanf("%d",&n);

	printf("\nEnter binary inputs: ");
	for(int i=0; i<n; i++) {
		scanf("%d",&binary_arr[i]);
	}

	printf("\nEnter element to find frequency: ");
	scanf("%d",&find_freq);

	//converting to decimal
	int temp,quot,rem,prod,sum,power=1;
	for(int i=0; i<n; i++) {
		temp = binary_arr[i];
		power=1;
		sum=0;
		for(;;) {
			quot = temp/10;
			rem = temp%10;
			prod = rem*power;
			sum += prod;
			temp = quot;
			power *=2 ;
			if(quot == 0) {
				break;
			}
		}
		decimal_arr[i] = sum;
	}

	printf("\n\nDecimal array after conversion: ");
	for(int i=0; i<n; i++) {
		printf("%d ",decimal_arr[i]);
	}

	//sorting in ascending order
	for(int i=0; i<n; i++) {
		for(int j=i+1; j<n; j++) {
			if (decimal_arr[i] > decimal_arr[j]) {
				temp = decimal_arr[i];
				decimal_arr[i] = decimal_arr[j];
				decimal_arr[j] = temp;
			}
		}
	}

	printf("\n\nSorted decimal array: ");
	for(int i=0; i<n; i++) {
		printf("%d ",decimal_arr[i]);
	}

	int temp1 = find_freq;
	power=1;
	sum=0;
	for(;;) {
		quot = temp1/10;
		rem = temp1%10;
		prod = rem*power;
		sum += prod;
		temp1 = quot;
		power *=2 ;
		if(quot == 0) {
			break;
		}
	}
	int deci_find_freq = sum;

	//finding the freq of "deci_find_freq"
	int count = 0;
	for(int i=0; i<n; i++) {
		if(decimal_arr[i] == deci_find_freq) {
			count++;
		}
	}

	printf("\n\nFrequency of element %d (decimal %d) in the sorted array: %d",find_freq,deci_find_freq,count);
	return 0;
}
