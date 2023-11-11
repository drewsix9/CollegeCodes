// Ctrl + D - Deletes the line of code where the pointer is.
// Ctrl + E - Duplicates the line of code.
// Ctrl + . - Turns the line of code into a comment.
// Ctrl + . - Turns the line of comment into a code.
// Ctrl + Shift + A - Format alignment.
// Ctrl + M - Splitscreen.
// Ctrl + Tab - Switch to a different window.
// Ctrl + G - go to line n.
// Ctrl + I - Incremental Search.
#include <stdio.h>
#include <stdlib.h>

int main() {

	float num1, num2;

	printf("Enter num: \n");
	scanf("%f",&num1);

	num2 = num1 -(int)num1;
	
	printf("%f", num1);

}
