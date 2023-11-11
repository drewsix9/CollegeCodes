#include <stdio.h>
#include <stdlib.h>

int main() {
	int size,arr[100];

	printf("Enter array size: ");
	scanf("%d",&size);

	printf("Enter array: ");

	for(int i=0; i<size; i++) {
		scanf("%d",&arr[i]);
	}
		
	for(int i=0; i<size; i++) {
		for (int j=i+1; j<size; j++) {

			if(arr[i]==arr[j]) {

				for(int k=j; k<size-1; k++) {
					arr[k]=arr[k+1];
				}
				size--;	
				j--;
			}
		}
	}

	printf("\nUnique elements in the array are: ");
	for(int i=0; i<size; i++) {
		printf("%d ",arr[i]);
	}

	return 0;
}
