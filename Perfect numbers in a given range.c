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

	int num,j,k,total;

	printf("This program tells if the number you entered is a perfect number\n Enter the range to print all perfect numbers: \t");
	scanf("%d", &num);

	for (j=2; j<num; j++) {
		total=0;

		for (k=1; k<j; k++) {
			if (j%k==0) {
				total=total+k;
			}

		}

		if (total==j) {
			printf("\n%d\n",j);
		}
	}
	return 0;
}
