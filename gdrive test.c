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
	
	char name[99];
	int n;
	
	printf("Enter your name:\t");
	gets(name);
	
	printf("Enter how many:\t");
	scanf("%d",&n);
	
	printf("\n");
	for(int i=1;i<=n;i++){
		printf("%s\n",name);
	}
	
	return 0;
}
