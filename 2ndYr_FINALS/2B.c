#include <stdio.h>
#include <stdlib.h>

int main() {
	int num,arr[100],n,freq[100];

	printf("Enter inputs: ");
	do {
		scanf("%d",&num);
		if(num != 0) {
			arr[n] = num;
			n++;
		}
	} while(num != 0);

	//assigning all freq to -1
	for(int i=0; i<n; i++) {
		freq[i] = -1;
	}

	//finding the freq of each element
	int count;
	for(int i=0; i<n; i++) {
		count=1;
		for(int j=i+1; j<n; j++) {
			if(arr[i] == arr[j]) {
				count++;
				freq[j]=0;
			}
		}
		if(freq[i]!= 0) {
			freq[i]=count;
		}
	}

	printf("\n");
	for(int i=0; i<n; i++) {
		if (freq[i] == 1 ) {
			printf("%d ",arr[i]);
		}
	}
	printf("\n");

	return 0;
}
