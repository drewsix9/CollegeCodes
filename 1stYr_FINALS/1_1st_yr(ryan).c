#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	/**
	Write a program that will insert elements in an array. 
	The new element can only be inserted if the number occupying
	the position is a prime number.
	Illustration:
	Enter number of input(s): 5
	Enter input(s): 10 2 3 4 5
	Enter elements to be inserted: 23 24
	Enter the positions: 2 4
	Output:
	Array after insertion: 10 2 3 24 4 5
	**/
	int n;
	printf("Enter number of inputs:");
	scanf("%d", &n);
	int array[n];
	int duparray[n];
	printf("Enter input(s):");
	for (int i=0; i<n; i++) {
		scanf("%d", &array[i]);
		duparray[i]=array[i];
	}
	int j=0;
	int elemsArray[n];
	
	printf("Enter elements to be inserted:");
	while (1==1) {
		scanf("%d", &elemsArray[j]);
		if (elemsArray[j]==0) {
			break;
		}
		j++;
	}
	int positionsArray[j];
	int cannotbeInserted[j];
	int idk=0;
	printf("Enter the positions:");	
	for(int i=0; i<j; i++) {
		scanf("%d", &positionsArray[i]);
	}
	printf("Output:");
	for(int i=0; i<j; i++) {
		int position = positionsArray[i];
		int num = duparray[position];
		int count=0;
		for (int k=2; k<num; k++) {
			if (num%k==0) {
				count++;
			} 
		}
		if (count!=0) {
			printf("\nElement %d cannot be inserted. \n", elemsArray[i]);
		} else {
			int lol=n-position;
			int newArray[lol];
			
			//1. Copy the numbers from the original array
			int q=0;
			for (int l=position; l<=n; l++) {
			newArray[q]=array[l];
			q++;
			}
			
			//2. Replace the array in that position with the said number.
			//3. Then on the next ones paste the new Array.
			int m=0;
			for (int y=position; y<=n+1; y++) {
				if(y==position) {
					array[y]=elemsArray[i];
					
				} else {
				array[y]=newArray[m];
				m++;
			}
			}
			
			
			
		}
	}
	
	printf("\nArray after insertion: \n");
			for (int x=0; x<=n+1; x++) {
			printf("%d ", array[x]);	
			}
	return 0;
}