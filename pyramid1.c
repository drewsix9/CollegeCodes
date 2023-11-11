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
	int row, c, n;
	printf("Enter the number of rows in pyramid of star to print: ");
	scanf("%d", &n);

	for (row=1;row<=n;row++){
		for (c=1;c<=n-row;c++){
			printf(" ");
		}
		for (c=1;c<=2*row-1;c++){
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
