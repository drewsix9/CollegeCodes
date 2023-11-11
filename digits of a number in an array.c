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
#include <math.h>
#define MAX 100

int main() {

	float quot,rem,num=852.3;
	int n;
	int counter=1;
	int digit[counter];

	n = num;

	while(n!=0){
		quot=num/10;
		rem=fmod(num,10);
		digit[counter]=rem;
		num=quot;
		counter++;
	}

	printf("%d\n",digit[1]);
	printf("%d\n",digit[2]);
	printf("%d\n",digit[3]);
	
	return 0;
}

                      