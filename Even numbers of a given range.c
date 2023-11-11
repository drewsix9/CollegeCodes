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

	int num, j,k;

	printf("Enter the range of which to print all even numbers:\n");
	scanf("%d",&num);

	for (j=2; j<num; j++) {
		if(j%2==0) {
			printf("%d ",j);
		}

	}

	return 0;
}
