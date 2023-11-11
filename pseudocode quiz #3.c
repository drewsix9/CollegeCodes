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
#include <stdio.h>
#include <stdlib.h>

int main() {
	
	int num;
	
	printf("Enter binary:\t");
	scanf("%d",&num);
	
	int quot,rem,prod,sum,power=1;

	for (;;) {
		quot = num / 10;
		rem = num % 10;
		prod = rem * power;
		sum = sum + prod;
		num = quot;
		power *= 2;
		if (quot == 0) {
			break;
		}
	}
	int factor=0;
	for (int i=1; i<=sum; i++) {
		if(sum%i==0) {
			factor++;
		}
	}
	if (factor==0) { //prime
		printf("\n%d, Prime Number",sum);
	} else { //comp
		printf("\n%d, Composite Number",sum);
	}
	return 0;
}
