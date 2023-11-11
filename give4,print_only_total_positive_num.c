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
	
	float sum=0,num1,num2,num3,num4;
	
	printf("Enter num1");
	scanf("%f",&num1);
	printf("Enter num2");
	scanf("%f",&num2);
	printf("Enter num3");
	scanf("%f",&num3);
	printf("Enter num4");
	scanf("%f",&num4);
	
	if(num1>0){
		
		sum=sum+num1;
	}
	if(num2>0){
		
		sum=sum+num2;
	}
	if(num3>0){
		
		sum=sum+num3;
	}
	if(num4>0){
		
		sum=sum+num4;
	}
	
	printf("\ntotal of positive numbers:\t%.2f",sum);



	return 0;
	
}
