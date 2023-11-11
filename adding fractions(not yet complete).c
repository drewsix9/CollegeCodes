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

	int nume=0,deno=0,a1,a2,b1,b2;
	int x,y;

	printf("Enter fraction1 n/n:\t");
	scanf("%d/%d",&a1,&a2);
	printf("\nEnter fraction2 n/n:\t");
	scanf("%d/%d",&b1,&b2);

	if (a2==b2) {

		nume=a1+b1;
		deno=a2;
		printf("\n%d/%d",nume,deno);

		if(nume==deno) {
			printf("\n1");
		}
	}
	if (a2!=b2) {
		deno=a2*b2;
		x=a1*b2;
		y=b1*a2;
		nume=x+y;

		printf("\n%d/%d",nume,deno);
		
	}

	return 0;
}
