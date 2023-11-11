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
	int power=1,quot,rem,prod,sum;
	int num=7;

	for(;;) {
		quot=(int)num/10;
		rem=(int)num%10;
		prod=rem*power;
		sum=sum+prod;
		num=quot;
		power*=2;
		if(quot==0) {
			break;
		}
	}

	printf("%d",sum);


	return 0;
}
