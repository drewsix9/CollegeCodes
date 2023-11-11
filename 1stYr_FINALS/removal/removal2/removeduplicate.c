#include <stdio.h>
#include <stdlib.h>

int main() {
	int num,n=0,arr[100];

	printf("Enter inputs: ");

	do {
		scanf("%d",&num);
		if(num!=0) {
			arr[n]=num;
			n++;
		}
	} while(num!=0);

	for(int i=0; i<n; i++) {
		for(int j=i+1; j<n; j++) {
			if(arr[i] == arr[j]) {
				
				for(int k=j; k<n; k++) {
					arr[k]=arr[k+1];
				}
				n--;
				j--;
			}
		}
	}

	printf("\n");
	for(int i=0; i<n; i++) {
		printf("%d ",arr[i]);
	}



	return 0;
}
