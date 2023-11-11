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
int num[100],length,arr[100];
	int count;
	int ihap[count];
	int counter[count];

	printf("Enter how many inputs:\t");
	scanf("%d",&length);

	for(int i=1; i<=length; i++) {

		printf("Enter inputs:\t");
		scanf("%d",&arr[i]);

	}

	int fr[length];    
    int visited = -1;    
        
    for(int i = 0; i < length; i++){    
        int count = 1;    
        for(int j = i+1; j < length; j++){    
            if(arr[i] == arr[j]){    
                count++;    
                //To avoid counting same element again    
                fr[j] = visited;    
            }    
        }    
        if(fr[i] != visited) 
		{
            fr[i] = count;    
        }
         for(int i = 0; i < length; i++){    
        if(fr[i] != visited){    
            printf("    %d occurs %d times \n", arr[i],fr[i]);    
              
        }    
    }    

	return 0;
}
}
