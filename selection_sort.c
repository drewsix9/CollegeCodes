//selection sort

#include <stdio.h>
#include <stdlib.h>

int main() {

	int a[]= {	,9,7,6,4,0,2,3,8,1};
	int length = 10;

	//before
	for(int i=0; i<length; i++) {
		printf("array [%d] = %d\n",i,a[i]);
	}

	//sorting
	for(int i=0; i<(length-1); i++) {
		int min_pos = i;
		for (int j=i+1; j<length; j++) {
			if (a[j]<a[min_pos]) {
				min_pos=j;
			}
		}

		if(min_pos!=i) {
			int temp = a[i];
			a[i]=a[min_pos];
			a[min_pos]=temp;
		}
	}
	printf("\n\n");

	//after
	for(int i=0; i<length; i++) {
		printf("array [%d] = %d\n",i,a[i]);
	}



	return 0;
}
