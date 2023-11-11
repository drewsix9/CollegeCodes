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

	int rem=0, rev=0,num;

	printf("Enter num to reverse:\t");
	scanf("%d", &num);

	while (num>0) {
		rem=num%10;
		rev=rev*10+rem;
		num=num/10;
	}

	printf("%d",rev);


	return 0;
}
