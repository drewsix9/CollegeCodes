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
/*Enter how many num: 3
122
123
122

122 occurs 2 times
123 occurs 1 time
*/
#include <stdio.h>
#include <stdlib.h>

int main() {

	int count;
	int num[count];
	int counter[count];

	printf("Enter how many inputs:\t");
	scanf("%d",&count);

	for(int i=1; i<=count; i++) {

		scanf("%d",&num[i]);
	}

//	for(int o=1;o<=count; o++){
//
//		printf("%d ",num[o]);
//	}

	for(int j=1; j<=count; j++) {
		for(int k=1; k<=count; k++) { //occured once.
			if (num[j]==num[k] && j!=k) {
				counter[j]=counter[j]+1;
			}
		}
	}

	for (int l=1; l<=count; l++) {
		if(counter[l]>1) {
			printf("%d = occured: %d times",num[l],counter[l]);
			printf("\n");
		}
	}


	printf("\n");
	printf("%d = occured %d times",num[1],counter[1]);



	return 0;
}
