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

void reversed(int n);

int main() {

	int inputs;

	printf("Enter how many intputs:\t"); // "\t" means to indent.
	scanf("%d",&inputs);

	for (int i=1; i<=inputs; i++) { //loop for how many inputs

		float num,temp;

		printf("\nEnter number %d:\t",i);
		scanf("%f",&num);

		temp=num-(int)num; //determines if there is a decimal number.

		if(temp==0) { //if there is no decimal number, this executes.

			int temp1=num;
			int quot=0,rem=0;

			printf("\n%d is an integer.\n",temp1);

			reversed(num);

			printf(" in reverse form.\n");

		} else { //if there is a decimal number, this executes
			printf("\n%f is not an integer\n",num);
		}
	}
	return 0;
}

void reversed(int n) {
	for(;;) { //infinite loop for reversing a number
		int quot,rem;
		quot=(int)n/10;
		rem=(int)n%10;
		printf("%d",rem);
		n=quot;
		if(quot==0) {
			break;
		}
	}
}