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
	
	int input,num,sum=0;
	
	printf("Enter how many inputs:\t");
	scanf("%d",&input);
	
	for(int i=0;i<input;i++){
		
		printf("\nEnter Input:\t");
		scanf("%d",&num);
		
		if (num>0){
			sum=sum+num;
		}
		
	}
	
	printf("\ntotal of positive numbers:\t%d",sum);

	return 0;
}
