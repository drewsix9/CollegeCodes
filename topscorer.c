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
#define MAX 100

int main() {
	int count;
	int score[MAX];

	printf("Enter the number of goal-scorers:\t");
	scanf("%d",&count);

	for(int i=1; i<=count; i++) {
		printf("Score of player #%d:\t",i);
		scanf("%d",&score[i]);
	}

	int temp;

	for(int i=1; i<=count; i++) {

		for(int j=i+1; j<count; j++) {

			if(score[i]>score[j]) {
				
				temp = score[i];
				score[i]=score[j];
				score[j]=temp;
			}
		}
	}
	printf("\nHighest to lowest:\n");
	
	for(int i=1;i<=count;i++){
		printf("Player number #%d: %d",i,score[i]);
		printf("\n");
	}
	
	

	return 0;
}
