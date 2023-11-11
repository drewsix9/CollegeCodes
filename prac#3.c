#include <stdio.h>
#include <stdlib.h>

int main() {

	int arr[100] = {1,2,3,4,5};
	int num = 3;
	int index = -1;
	int is_repeating=0;
	int is_index=0;
	int count=0;

	for (int j=0; j<5; j++) {
		for (int k=0; k<5; k++) {
			if (arr[j] == arr[k] && num == arr[j] && j!=k) {
				is_repeating=1;
				count++;
			} else {
				is_index=1;
			}
		}
	}

	if(is_repeating==1) {
		printf("count = %d",count);
	} else {
		printf("\n%d",index);
	}

	return 0;
}
