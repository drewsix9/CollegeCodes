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
//================================
//Enter a number with decimals
//Print the decimals
//Print the whole number
//Tell wheather it is a whole number or not

#include <stdio.h>
#include <stdlib.h>

int main() {

	float num,num1;

	printf("Enter a number with decimals:\t");
	scanf("%f", &num);

	num1=num-(int)num;
	printf("================================================================\n\tDecimal is:\t\t%.2f",num1);
	num=(int)num;
	printf("\n\tWhole Number is:\t%.0f",num);
	
	num=num+num1;
	
	if(num1=0) {
		printf("\n\t%.2f is a whole number\n================================================================",num);
	} else {
		printf("\n\n\t%.2f is a NOT whole number\n================================================================",num);
	}

	return 0;
}
