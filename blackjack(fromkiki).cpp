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

	int x,y,z,total;

	printf("Enter 3 card numbers ##/##/##:\t");
	scanf("%d/%d/%d",&x,&y,&z);

	total = x + y + z;

	//if a number is equal to 1 and the total of all numbers is lesser than 21, add 10
	if ((total<21) && (x==1) || (y==1) || (z==1)) {
		total = total + 10;
	//If total is greater than 21, subtract 10
		if (total>21) {
			total = total - 10;
		}

	}
	if (total==21) {
		printf ("\n %d BLACK JACK! \n",total);
	} else {
		printf ("\n %d BOKYA! \n",total);

	}

	return 0;
}
