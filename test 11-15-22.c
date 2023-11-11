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

int main(){
	
	int num, factor,j,k;
	
	printf("Enter love range of christian to cleo kyts:\t");
	scanf("%d",&num);
	printf("\n");
	
	for(k=2;k<num;k++){
		
		factor=0;
		
		for(j=2;j<k;j++){
			
			if(k%j==0){
				
				factor++;
			}
		}
		if (factor==0){
			
			printf("%d ",k);
		}
	}
return 0;
}
