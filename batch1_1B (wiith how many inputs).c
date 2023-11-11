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

int reversed(int n);

int main() {

	int inputs;

	printf("Enter how many inputs:\t");
	scanf("%d",&inputs);

	for (int j=1; j<=inputs; j++) {

		float num, temp=0;
		int rem=0, rev=0;

		printf("\nEnter number %d:\t",j);
		scanf("%f",&num);

		temp = num - (int)num;

		if (temp==0) {

			int temp1=0;
			temp1=num;

			rev = reversed(num);

			printf("\n%d is an integer and %d in reverse.\n",temp1,rev);

		} else {
			printf("\n %f is not an integer.\n",num);

		}
	}


	return 0;
}

int reversed(int num) {
	int rem=0,rev=0;

	while(num>0) {
		rem=(int)num%10;
		rev=rev*10+rem;
		num=(int)num/10;
	}
	return rev;
}