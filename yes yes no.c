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

//yes = positive, odd, between 15-30
//no = else


#include <stdio.h>
#include <stdlib.h>

int main() {
	
	int num;

	printf("Enter num:\t");
	scanf("%d",&num);
	
	if(num>=15 && num<=30 && num%2!=0){
		
		printf("\nYES!\n");
		
	}else {
		printf("\nNO!\n");
		
	}
	
	

	return 0;
}
