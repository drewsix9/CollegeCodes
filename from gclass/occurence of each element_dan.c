#include <stdio.h>
#include <stdlib.h>

int main() {

	int size,arr[100],arrcount[100],count;

	printf("Enter size of array: ");
	scanf("%d",&size);

	printf("\nEnter elements: ");

	for(int i=0; i<size; i++) {
		scanf("%d",&arr[i]);
		arrcount[i] = -1;
	}

//	for(int i=0; i<size; i++) {
//		printf("%d\n",a[i]);
//	}

	//counting each element of an array
	for(int i=0; i<size; i++) {
		count=1;
		for(int j=i+1; j<size; j++) {
			
			if (arr[i] == arr[j]) {
				count++;
				arrcount[j]=0;
			}
		}
		if(arrcount[i] != 0) {
			arrcount[i] = count;
		}
	}

	printf("\nFrequency of all elements of array : \n");
	for(int i=0; i<size; i++) {
		if (arrcount[i] != 0) {
			printf("%d occurs %d times\n",arr[i],arrcount[i]);
		}
	}


	return 0;
}
