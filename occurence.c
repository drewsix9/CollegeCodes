// Ctrl + D - Deletes the line of code where the pointer is.
// Ctrl + E - Duplicates the line of code.
// Ctrl + . - Turns the line of code into a comment.
// Ctrl + . - Turns the line of comment into a code.
// Ctrl + Shift + A - Format alignment.
// Ctrl + M - Splitscreen.
// Ctrl + Tab - Switch to a different window.
// Ctrl + G - go to line n.
// Ctrl + I - Incremental Search.
// Alt + up/down - to move the line of code up or down
//--------------------------------
/*Enter how many num: 3
122
123
122

122 occurs 2 times
123 occurs 1 time
*/
#include <stdio.h>
#include <stdlib.h>

int main() {

	int count;
	int ihap[count];
	int counter[count];

	printf("Enter how many inputs:\t");
	scanf("%d",&count);

	int num[count];

	for(int i=1; i<=count; i++) {

		printf("Enter inputs:\t");
		scanf("%d",&num[i]);

	}

	for(int k=1; k<=count; k++) { // 1 1 2
		ihap[k]=1;
		for( int l=1; l<=count; l++) { // 1 1 2
			if (num[k]==num[l] && k != l) {
				ihap[l]++;
			}
		}
	}
//	printf("%d occured %d times",num[2],ihap[2]); // TESTER


	int temp;

	for(int h=1; h<=count; h++) {
		printf("\n");
		if (ihap[h]>1) {
			temp = num[h];
			printf("%d occured %d times",num[h],ihap[h]);
			printf("\n");
		counter[h]++;
			if(num[h]==temp) {
			}
		} else {
			printf("%d occured %d times",num[h],ihap[h]);
			printf("\n");
		}
	}

//	for (int q=1; q<=count; q++) { //if i try to make this a code, ma blank ra ang output idk why.
//		if (ihap[q]==1) {
//			printf("%d occured %d times",num[q],ihap[q]);
//			printf("\n");
//		}
//	}

	return 0;
}
