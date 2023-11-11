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

	int rows;

	printf("Enter numer of rows:\t");
	scanf("%d",&rows);
	printf("\n");

	for(int i=1; i<=rows; i++) {
		for(int j=1; j<=i; j++) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
