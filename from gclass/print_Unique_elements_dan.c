#include <stdio.h>
#include <stdlib.h>

int main() {

	// {2,1,3,7,1,3,1};
	// {2,7};

	int arr[100],size,freq[100],count;

	printf("Enter array size: ");
	scanf("%d",&size);

	printf("Enter array: ");

	for(int i=0; i<size; i++) {
		scanf("%d",&arr[i]);
		freq[i] = -1;
	}

	for(int i=0; i<size; i++) {
		count=1;
		for(int j=i+1; j<size; j++) {

			if(arr[i]==arr[j]) {
				count++;
				freq[j]=0;
			}
		}
		if(freq[i]!=0) {
			freq[i]=count;
		}
	}

	for(int i=0; i<size; i++) {
		if(freq[i] == 1) {
			printf("%d ", arr[i]);
		}
	}

//printf("\n\n");
//	for(int i=0; i<size; i++) {
//		printf("array%d = %d = %d\n",i,arr[i],freq[i]);
//	}
	return 0;
}
