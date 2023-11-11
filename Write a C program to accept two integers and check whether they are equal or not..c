// Ctrl + D - Deletes the line of code where the pointer is.
// Ctrl + E - Duplicates the line of code.
// Ctrl + . - Turns the line of code into a comment.
// Ctrl + . - Turns the line of comment into a code.
// Ctrl + Shift + A - Format alignment.
// Ctrl + M - Splitscreen.
// Ctrl + Tab - Switch to a different window.
// Ctrl + G - go to line n.
// Ctrl + I - Incremental Search.
//--------------------------------
#include <stdio.h>
#include <stdlib.h>

int main(){

int num1, num2;

printf("Enter 1st number: \n");
scanf("%d", &num1);
printf("Enter 2nd number: \n");
scanf("%d", &num2);

if (num1 == num2){
	printf("%d and %d are EQUAL", num1, num2);
}
else {
	printf("%d and %d are NOT EQUAL", num1, num2);
}

return 0;
}
