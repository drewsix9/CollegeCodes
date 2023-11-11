#include <stdio.h>
#include <stdlib.h>

int main() {

	int arr[100] = {2,8,7,4,5,1,9,3};
	int n = 8;

	for(int i=1; i<n; i++) {
		int key = arr[i];
		int j = i-1;
		while(j >= 0 && arr[j] > key) {
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}

	printf("\n");
	for(int i=0; i<n; i++) {
		printf("%d ",arr[i]);
	}

	return 0;
}
